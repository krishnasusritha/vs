#include <iostream>
using namespace std;
class sort
{
	int *a;
	int n;
public:
	sort()
	{
		a = NULL;
		n = 0;
	}
	sort(int n1)
	{
		n = n1;
		a = new int[n];
		for (int i = 0; i < n; i++)
			cin >> a[i];
	}
	void sel()
	{
		int temp, j, loc;
		for (int i = 0; i < n - 1; i++)
		{
		    j = i + 1, loc = i;
			for (j; j < n - 1; j++)
			{
				if (a[j] < a[loc])
					loc = j;
			}
			temp = a[i];
			a[i] = a[loc];
			a[loc] = temp;
		}
	}
	void bub()
	{
		int i, j, t;
		for (i = 0; i < n - 1; i++)
		{
			for (j = 0; j < n - i - 1; j++)
			{
				if (a[j] > a[j + 1])
				{
					t = a[j];
					a[j] = a[j + 1];
					a[j + 1] = t;
				}
			}
		}
	}
	void insert()
	{
		int i, j, temp;
		for (i = 1; i < n; i++)
		{
			j = i - 1;
			temp = a[i];
			while (j >= 0 && a[j - 1] > temp)
			{
				a[j + 1] = a[j];
				j--;
			}
			a[j + 1] = temp;
		}
	}
		void mergesort(int low, int high)
		{
			int mid = 0;
			if (low < high)
			{
				//low = 0;
				//high = n - 1;
				mid = (low + high) / 2;
				mergesort(low, mid);
				mergesort(mid + 1, high);
				merge(low, mid, high);
			}
		}
		void merge(int l1s,int l1e,int l2e)
		{
			int l2s = l1e + 1;
			int *l3,i,k;
			i = l1s;
			k = 0;
			int j = l2e + 1;
			l3 = new int[l2e - l1s + 1];
			while (i <= l1e&&j <= l2e)
			{
				if (a[i] > a[j])
					l3[k++] = a[j++];
				else
					l3[k++] = a[i++];
			}
			while (i <= l1e)
			{
				l3[k++] = a[i++];
			}
			while (j <= l2e)
			{
				l3[k++] = a[j++];
			}
			while (l2e >=l1s)
				a[l2e--] = l3[--k];
			delete(l3);
	}

};
	int main()
	{
		sort s1(5), s2(6), s3(7);
		s1.bub();
		s2.sel();
		s3.mergesort(0,6);
		return 0;
	}
