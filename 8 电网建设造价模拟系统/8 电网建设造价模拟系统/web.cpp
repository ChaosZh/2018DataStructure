#include "web.h"
Web::Web()
{
    construction();
}


Web::~Web()
{
    delete[]nodeList;
    delete[]nearVec;
    delete[]lowCost;
    for (int i = 0; i < nodeNum; i++)
    {
        delete[]cost[i];
    }
}

void Web::construction()
{
    char input;
    bool flag = 1;

    while (flag)
    {
        cout << endl << "��ѡ�������";
        cin >> input;

        switch (input)
        {
            //���붥����Ϣ
        case'A':
            cout << "�����붥��ĸ�����";
            cin >> nodeNum;
            nodeList = new Node[nodeNum];
            cout << "�������������������ƣ�" << endl;
            char _name;
            //��������������Ϣ
            for (int i = 0; i < nodeNum; i++)
            {
                cin >> _name;
                nodeList[i].setName(_name);
                nodeList[i].setIndex(i);
            }
            //��ʼ��
            nearVec = new bool[nodeNum];
            lowCost = new int[nodeNum];
            cost = new int*[nodeNum];
            for (int i = 0; i < nodeNum; i++)
            {
                nearVec[i] = 0;
                lowCost[i] = INT_MAX;
                cost[i] = new int[nodeNum];
                for (int j = 0; j < nodeNum; j++)
                {
                    cost[i][j] = INT_MAX;
                }
            }

            break;
            //���붥��ıߵ���Ϣ
        case'B':
            cout << "���붥��ͱߵ���Ϣ����Ҫ��ֹ���룬����? ? 0" << endl;
            while (true)
            {
                char a, b;
                int l;
                cout << "�������������㼰�ߣ�";
                cin >> a >> b >> l;

                if (a == '?'&&b == '?'&&l == 0)
                {
                    cout << "�ߵ���Ϣ������ɡ�" << endl;
                    break;
                }
                else
                {
                    int indexA = getIndex(a);
                    int indexB = getIndex(b);
                    cost[indexA][indexB] = cost[indexB][indexA] = l;
                }
            }
            break;

            //������ʼ���㲢����Prim��С������
        case'C':
            cout << "��������ʼ���㣺";
            char start;
            cin >> start;
            nearVec[getIndex(start)] = 1;
            count++;
            buildTree();
            cout << "����Prim��С��������" << endl;
            break;
            //��ʾ��С������
        case'D':
            showTree();
            break;
            //�˳�����
        case'E':
            flag = 0;
            break;
        }
    }
}

int Web::getIndex(char name)
{
    for (int i = 0; i < nodeNum; i++)
    {
        if (nodeList[i].getName() == name)
        {
            return nodeList[i].getIndex();
        }
    }
    return -1;
}

char Web::getName(int index)
{
    for (int i = 0; i < nodeNum; i++)
    {
        if (nodeList[i].getIndex() == index)
        {
            return nodeList[i].getName();
        }

    }
    return 0;
}

void Web::buildTree()
{
    //�洢��δ֪��i��С�������֪��j
    int* lowCostNode = new int[nodeNum];
    //update lowCost
    //��δ֪��i����֪��j����С����
    for (int i = 0; i < nodeNum; i++)
    {
        if (nearVec[i] == 1)continue;
        for (int j = 0; j < nodeNum; j++)
        {
            if (nearVec[j] != 1)continue;
            if (cost[i][j] <= lowCost[i])
            {
                lowCost[i] = cost[i][j];
                lowCostNode[i] = j;
            }
        }
    }

    //����lowCostѡ���¼���ĵ�
    int addNode = 0;
    int minCost = lowCost[0];
    for (int i = 1; i < nodeNum; i++)
    {
        if (nearVec[i] == 1)continue;
        if (minCost > lowCost[i])
        {
            minCost = lowCost[i];
            addNode = i;
        }
    }

    //update nearVec
    nearVec[addNode] = 1;
    count++;

    //����ߵ���ѡ������edge��
    Edge edgeTemp(lowCost[addNode], getName(addNode), getName(lowCostNode[addNode]));
    edge.push_back(edgeTemp);
    if (count != nodeNum)buildTree();
    return;
}

void Web::showTree()
{
    auto iter = edge.begin();
    while (iter != edge.end())
    {
        cout << iter->start << "-<" << iter->length << ">->" << iter->end << '\t';
        iter++;
    }
    return;
}