#include "CriticalPath.h"

CriticalPath::CriticalPath()
{
    int TaskNum;
    cout << "����ؼ�������񽻽ӵ�����N����������M��";
    cin >> PointNum >> TaskNum;

    //��ʼ���ڽӱ�
    point = new Point[PointNum];
    indegree = new int[PointNum];
    Vearly = new int[PointNum];
    Vlate = new int[PointNum];
    for (int i = 0; i < PointNum; i++)
    {
        point[i].name = i;
        indegree[i] = 0;
        Vearly[i] = 0;
        Vlate[i] = INT_MAX;
    }

    cout << "��������������루����ʼ���ӵ㡢������ɽ��ӵ㡢�����������ʱ�䣩��" << endl;
    for (int i = 0; i < TaskNum; i++)
    {
        int a, b, cost;
        cin >> a >> b >> cost;
        //��ӵ��ڽӱ���
        point[a - 1].appendEdge(new Edge(b - 1, cost));
        indegree[b - 1]++;
    }

    if (TopologicalSort())
    {
        printPath();
    }
    else
    {
        cout << "�����еķ������ԡ�" << endl;
    }
}


CriticalPath::~CriticalPath()
{
    //ɾ��point��edges
    for (int i = 0; i < PointNum; i++)
    {
        Edge* e = point[i].adj;
        while (e != nullptr)
        {
            Edge*_e = e;
            e = e->next;
            delete _e;
        }
    }

    //ɾ��
    delete[] point;
    delete[] indegree;
    delete[] Vearly;
    delete[] Vlate;
}

bool CriticalPath::TopologicalSort()
{
    int top = -1;	//ջ��ָ��
    int* topologicalPath = new int[PointNum];	//��������
    for (int i = 0; i < PointNum; i++)
    {
        if (indegree[i] == 0)
        {
            indegree[i] = top;
            top = i;
        }
    }

    int topoIndex = 0;
    while (top != -1)	//ջ��Ϊ��
    {
        int lastTop = top;		//���¸ոռ����������еĵ����
        top = indegree[top];	//��ջ

        Edge* edge = point[lastTop].adj;	//Top��������ڱ�
        topologicalPath[topoIndex] = lastTop;	//�����������
        topoIndex++;

        while (edge != nullptr)
        {
            indegree[edge->name]--;
            Vearly[edge->name] = max(Vearly[edge->name], Vearly[lastTop] + edge->cost);		//����Vearly����
            if (indegree[edge->name] == 0)
            {
                indegree[edge->name] = top;
                top = edge->name;
            }
            edge = edge->next;
        }
    }

    if (topoIndex < PointNum)return false;	//�������в����ǻ����ͼ�����н�㣬˵���л�·��

    //�������Vlate��˳�����ؼ�·��
    Vlate[topoIndex - 1] = Vearly[topoIndex - 1];
    for (int i = topoIndex - 2; i > -1; i--)
    {
        Edge* edge = point[i].adj;
        while (edge != nullptr)
        {
            Vlate[i] = min(Vlate[edge->name] - edge->cost, Vlate[i]);	//����Vlate;
            edge = edge->next;
        }
        //���㵱ǰ���Ƿ��йؼ�·��
        edge = point[i].adj;
        while (edge != nullptr)
        {
            if (Vlate[edge->name] - edge->cost == Vearly[i])
            {
                Path p;
                p.begin = i;
                p.end = edge->name;
                criticalPath.push(p);
            }
            edge = edge->next;
        }
    }

    delete[]topologicalPath;
    return true;
}

void CriticalPath::printPath()
{
    cout << endl;
    cout << "���������Ŀ����ʱ����" << Vearly[PointNum - 1] << endl;
    cout << "�ؼ�·����" << endl;
    while (criticalPath.size() != 0)
    {
        auto p = criticalPath.top();
        cout << p.begin + 1 << "->" << p.end + 1 << endl;
        criticalPath.pop();
    }
    return;
}
