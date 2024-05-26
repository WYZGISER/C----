#include<iostream>
using namespace std;

#define MAX 1000



	//��װ������ʾ�ý���
	//��main�����е��÷�װ�õĺ���

//�˵�����
void showMain() {
	cout << "1�������ϵ��" << endl;
	cout << "2����ʾ��ϵ��" << endl;
	cout << "3��ɾ����ϵ��" << endl;
	cout << "4��������ϵ��" << endl;
	cout << "5���޸���ϵ��" << endl;
	cout << "6�������ϵ��" << endl;
	cout << "0���˳�����" << endl;
}

//�����ϵ��
//1�����һ����ϵ�˵Ľṹ��
//2�����ͨѶ¼�ṹ��
//3��main�����д���ͨѶ¼
//��װ�����ϵ�˺���
//���������ϵ�˹���


//�����ϵ�˽ṹ��
struct Person
{
	string m_Name;//����
	int m_Sex;//�Ա�
	int m_Age;//����
	string m_Phone;//�ֻ�����
	string m_Addr;//��ͥסַ
};

//���ͨѶ¼�ṹ��
struct Addressbooks {
	struct Person personArray[MAX];//ͨѶ¼�б������ϵ������
	int m_Size;//ͨѶ¼����Ա����

};

//�����ϵ��
void addPerson(Addressbooks *abs) {
	//�ж�ͨѶ¼�Ƿ�������������˾Ͳ������
	if (abs->m_Size== MAX)
	{
		cout << "ͨѶ¼�������޷����" << endl;
		return;
	}
	else
	{
		//��Ӿ������ϵ��

		//����
		string name;
		cout<<"����������" << endl;
		cin >> name;
		//�ŵ�ͨѶ¼����
		abs->personArray[abs->m_Size].m_Name = name;

		//�Ա�
		int sex = 0;
		cout << "�������Ա�1��ʾ�У�2��ʾŮ��" << endl;
		

		while (true)
		{
			cin >> sex;
			//�������1��2����˳�ѭ��
			//���������������������
			if (sex == 1 || sex == 2)
			{
				abs->personArray[abs->m_Size].m_Sex = sex;
				break;
			}
			else
			{
				cout << "��������ȷ��ֵ" << endl;
			}
		}
		
		

		//����
		int age;
		cout << "����������" << endl;
		

		while (true)
		{
			cin >> age;

			if (age > 1 && age < 100)
			{
				abs->personArray[abs->m_Size].m_Age = age;
				break;
			}
			else
			{
				cout << "��������ȷ������" << endl;
			}
		}	

		//�绰����
		string phone;
		cout << "������绰����" << endl;
		cin >> phone;
		abs->personArray[abs->m_Size].m_Phone = phone;


		//סַ
		string address;
		cout << "������סַ" << endl;
		cin >> address;
		abs->personArray[abs->m_Size].m_Addr = address;

		//����ͨѶ¼����
		abs->m_Size++;

		//��ӳɹ�
		cout << "��ӳɹ�" << endl;
		system("pause");
		system("cls");
	}
}

//��ʾ��ϵ�˹���
//˼·���ж������ǰͨѶ¼û����ϵ�ˣ�����ʾ��¼Ϊ�գ���������0����ʾͨѶ¼�е���Ϣ

//��ʾ��������Ϣ�ķ���
void showPerson(Addressbooks* abs) {
	//�ж�ͨѶ¼�������Ƿ�Ϊ0�����Ϊ0����ʾ��¼Ϊ��
	//�����Ϊ0����ʾ��¼����ϵ����Ϣ
	if (abs->m_Size==0)
	{
		cout << "��ǰͨѶ¼Ϊ��" << endl;
	}
	else
	{
		for (int i = 0; i < abs->m_Size; i++)
		{
			cout << "����: " << abs->personArray[i].m_Name <<" ";
			cout << "�Ա�: " << (abs->personArray[i].m_Sex == 1 ? "��" : "Ů") << " ";
			cout << "����: " << abs->personArray[i].m_Age << " ";
			cout << "�绰: " << abs->personArray[i].m_Phone << " ";
			cout << "סַ: " << abs->personArray[i].m_Addr << endl;

		}
	}
	system("pause");//�����������
	system("cls");//����
}


//ɾ����ϵ��
//1�������ϵ���Ƿ����
//2����װɾ����ϵ�˵ĺ���
//3������ɾ����ϵ�˵Ĺ���

//�����ϵ���Ƿ���ڣ�������ڣ�������ϵ�����������еľ���λ�ã������ڷ���-1				
//����1��ͨѶ¼ ����2���Աȵ�����
int isExist(Addressbooks * abs,string name) {
	for (int i = 0; i < abs->m_Size; i++)
	{
		//�ҵ��û����������
		if (abs->personArray[i].m_Name == name)
		{
			return i;//����������������е��±�
		}
	}
	return -1;//�������������ô���ҵ�
}//ɾ��ָ������ϵ��
void deletePerson(Addressbooks *abs)
{
	cout << "��������Ҫɾ������ϵ��" << endl;

	string name;

	cin >> name;
	int result = isExist(abs,name);//result == -1:δ�鵽��result==i���鵽�����±�Ϊi����
	if (result != -1)
	{
		for (int i = result; i < abs->m_Size; i++)
		{
			//����ǰ��
			abs->personArray[i] = abs->personArray[i + 1];
		}
		abs->m_Size--;//����ͨѶ¼������
		cout << "ɾ���ɹ�" << endl;

	}
	else
	{
		cout << "���޴��ˣ��޷�ɾ��" << endl;
	}

	system("pause");
	system("cls");
}


//������ϵ��
void findPerson(Addressbooks *abs)
{
	cout << "��������Ҫ���ҵ���ϵ��" << endl;
	string name;//�������������û�
	cin >> name;

	//�ж�ָ������ϵ���Ƿ����
	int ret = isExist(abs, name);
	if (ret != -1)//����
	{
		cout << "������" << abs->personArray[ret].m_Name << " ";
		cout << "�Ա�" << abs->personArray[ret].m_Sex << " ";
		cout << "���䣺" << abs->personArray[ret].m_Age << " ";
		cout << "�绰��" << abs->personArray[ret].m_Phone << " ";
		cout << "סַ��" << abs->personArray[ret].m_Addr<< " "<<endl;
	}
	else//������
	{
		cout << "���޴���" << endl;
	}

	system("pause");
	system("cls");
}

//�޸�ָ����ϵ����Ϣ
void modifyPerson(Addressbooks * abs) {
	cout << "������Ҫ�޸ĵ���ϵ��" << endl;
	string name;
	cin >> name;
	int ret = isExist(abs, name);
	if (ret != -1)
	{
		//����
		cout << "��������ϵ�˵�����" << endl;
		cin >> name;
		abs->personArray[ret].m_Name = name;
		//�Ա�
		cout << "��������ϵ�˵��Ա�" << endl;
		cout << "����--1" << endl;
		cout << "Ů��--2" << endl;
		int sex;
		
		while (true)
		{
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->personArray[ret].m_Sex = sex;
				break;
			}
			else
			{
				cout << "��������ȷ���Ա�" << endl;
			}
		}
		
		//����
		cout << "��������ϵ�˵�����" << endl;
		int age;
		cin >> age;
		abs->personArray[ret].m_Age = age;
		//�绰
		cout << "��������ϵ�˵ĵ绰" << endl;
		string phone;
		cin >> phone;
		abs->personArray[ret].m_Phone = phone;

		//סַ
		cout << "��������ϵ�˵�סַ" << endl;
		string adress;
		cin >> adress;
		abs->personArray[ret].m_Addr = adress;
	}
	else
	{
		cout << "���޴���" << endl;
	}

	system("pause");
	system("cls");
}

//�����ϵ��
//ʵ��˼·����ͨѶ¼��¼��¼����ϵ��Ϊ0
void cleanPerson(Addressbooks* abs) {
	abs->m_Size = 0;
	cout << "ͨѶ¼�����" << endl;
	system("pause");
	system("cls");
}


//�˳�ϵͳ

int main() {

	//��main�����д�����ʵ��ͨѶ¼
	Addressbooks abs;
	//��ʼ��ͨѶ¼�е�ǰ����Ա����
	abs.m_Size = 0;


	int select = 0;//�����û�ѡ������ı���

	string name;

	while (true)
	{
		showMain();
		cin >> select;

		switch (select)
		{
		case 1://�����ϵ��
			addPerson(&abs);//���õ�ַ���ݿ�������ʵ��
			break;
		case 2://��ʾ��ϵ��
			showPerson(&abs);
			break;
		case 3://ɾ����ϵ��
		{
			/*cout << "������Ҫɾ����ϵ�˵�����" << endl;
			cin >> name;
			if (isExist(&abs, name) == -1)
			{
				cout << "���޴���" << endl;
			}
			else
			{
				cout << "�ҵ�����" << endl;
			}
			system("pause");
			system("cls");*/
		}
			deletePerson(&abs);
			
			break;
		case 4://������ϵ��
			findPerson(&abs);
			break;
		case 5://�޸���ϵ��
			modifyPerson(&abs);
			break;
		case 6://�����ϵ��
			cleanPerson(&abs);
			break;
		case 0://�˳�ͨѶ¼
			cout << "��ӭ�´�ʹ��ͨѶ¼" << endl;
			system("pause");
			return 0;
			break;
		}
	}


	
	
	
}