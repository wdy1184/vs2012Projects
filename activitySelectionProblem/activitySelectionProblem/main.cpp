#include <iostream>

using namespace std;

#define maxValue 30000

struct activityTime  //�ṹ�����͵�˵���붨��ֿ��� ����
{
int sTime;	
int fTime;   
//activityTime* next;
};

int resultNum = 0;

/*
	����Ϊ��activityTime times[]�ʱ�� activityTime result[]��� int arrNum�ܻ�� int i��ʼ, int j����
	���ؽ������
	*/
void recursive_activity_selector(activityTime times[],activityTime result[], int arrNum, int i, int j);//�ݹ�����

int main()
{
	int numNum;
	//�����ĸ���
	cout << "������������(Ϊʵ������)��" << endl;
	cin >> numNum;
	numNum += 2;
	activityTime *arr = NULL;
	try
	{
		arr = new activityTime[numNum];//ʹ��new��������
		for (int i = 0; i < numNum; i++)
		{
			arr[i].sTime = -1;
			arr[i].fTime = -1;
		}
	}
	catch (exception e)
	{
		cout << "��������ʧ�ܡ�" << endl;
	}

	activityTime *result = NULL;
	try
	{
		result = new activityTime[numNum];//ʹ��new��������
		for (int i = 0; i < numNum; i++)
		{
			result[i].sTime = -1;
			result[i].fTime = -1;
		}
	}
	catch (exception e)
	{
		cout << "��������ʧ�ܡ�" << endl;
	}

	//��������
	cout << "������ÿ����Ŀ�ʼ�ͽ���ʱ�䣺" << endl;
	for (int i = 0; i < numNum; i++)
	{
		if (i == 0)
		{
			arr[i].sTime = 0;
			arr[i].fTime = 0;
		}
		else if (i == numNum-1)
		{
			arr[i].sTime = maxValue;
			arr[i].fTime = maxValue;
			cout << "���������" << endl;
		}
		else
		{
			cout << "��ʼ�����ʱ�䣺";
			cin >> arr[i].sTime >> arr[i].fTime;
		}
		
	}

	//�ݹ����
	recursive_activity_selector(arr, result, numNum, 0, numNum+1);

	for (int i = numNum-1; i >= 0; i--)
	{//&& result[i].sTime != maxValue
		if (result[i].sTime != -1 && result[i].sTime != maxValue)
		{
			cout << "s:" << result[i].sTime << "f:" << result[i].fTime << endl;
		}
	}

	delete []result;
	delete []arr;
}


void recursive_activity_selector(activityTime times[],activityTime result[], int arrNum, int i, int j)
{
	activityTime *returnTime = NULL;
	int m = i + 1;
	while (m < j && times[m].sTime < times[i].fTime)
	{
		m = m + 1;
	}
	if (m < j)
	{
		recursive_activity_selector(times, result, arrNum-1, m, j);
		for (int i = 0; i < arrNum; i++)
		{
			if (result[i].sTime == -1)
			{
				result[i].sTime = times[m].sTime;
				result[i].fTime = times[m].fTime;
			}
		}	
	}
}