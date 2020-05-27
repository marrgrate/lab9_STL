#include "9.1_func.h"

void menu()
{
	cout << "CHOOSE A TASK:\n"
		<< "\t1 - 7.1\n"
		<< "\t2 - 5.3\n"
		<< "\t3 - 7.2\n" << endl;
}

////////////////////////7_1///////////////////////
void task7_1()
{
	int n = 1e4;
	ifstream file("numbers.txt");
	if (!file)
	{
		cout << "file openning error\n";
		return;
	}
	else
	{
		vector<bool> v(n);
		initArray(v);
		int number;
		int cntr = 0;
		while (!file.eof() && cntr != n)
		{
			file >> number;

			if (!v[number])
			{
				v[number] = true;
				++cntr;
			}
		}

		vector<int> new_v(cntr);
		//формирование new_array
		int i = 0;
		for (int j = 0; j < n; j++)
			if (v[j])
			{
				new_v[i] = j;
				++i;
			}
		cout << endl;
		printArray(new_v);
		file.close();
		return;
	}
}
void initArray(vector<bool> array)
{
	for (int i = 0; i < array.size(); ++i)
		array[i] = false;
}
void printArray(vector<int> array)
{
	for (int i = 0; i < array.size(); i++)
		cout << array[i] << ' ';
}

////////////////////////5_3///////////////////////
void task5_3()
{
	//10. В предложении все слова начинаются с различных букв. Получить текст
	//(если можно), в котором слова предложения расположены в таком порядке,
	//чтобы последняя буква каждого слова совпадала с первой буквой следующего слова.

	vector<string> str;	//вектор слов типа string
	string buffer = "";
	
	std::cout << "Enter words. "
		<< "Enter empty string when finished" << std::endl;
	do 
	{
		rewind(stdin);
		getline(cin, buffer);
		if (buffer.size() > 0) {
			str.push_back(buffer);
		}
	} while (buffer != "");

	sort(str.begin(), str.end());
	vector<string>::iterator p = str.begin();
	vector<string> new_str;
	new_str.push_back(str[0]);
	bool flag = 0;
	int n = 0;

	for (int i = 0; i < str.size(); i++)
	{
		for (int j = 1; j < str.size(); j++)
		{
			if (new_str[0][(new_str[0].length() - 1)] == str[j][0])
			{
				new_str.push_back(str[j]);
				n++;
				str[j] = "0";
				flag = 1;
			}
			if (n > 0) break;
		}
		if (n == 0 && str[i] != "0")
			new_str.push_back(str[i]);
		n = 0;
	}
	if (!flag) { cout << "impossible to create such string";  }
	else
	{
		cout << endl;
		for (int i = 0; i < new_str.size(); i++)
			cout << new_str[i] << ' ';
		cout << endl;
	}
	return;
}

////////////////////////7_2///////////////////////
void task7_2()
{
	int size = 3;
	cout << "Enter natural number\t";
	unsigned n;
	cin >> n;

	//-----------------двумерный массив---------------//
	vector < vector <float> > A(size, vector <float>(size)); // Объявление вектора на n строк по m элементов 
	
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
			A[i][j] = rand() % 10;
	initMatrix(A, size);
	printMatrix(A, size);

	unsigned degree = 1;
	float sum;
	sum = calculateTrace(A, size);
	cout << "Degree: 0\t" << sum << endl << endl;
	while (degree < n)
	{
		A = multMatrix(A, size);
		printMatrix(A, size);
		sum += calculateTrace(A, size);
		cout << "Degree: " << degree << '\t' << sum << endl << endl;
		degree++;
	}
	//-----------------одномерный массив----------------//
	cout << "\n________________________________\n";
	vector<float> B(size * size);
	initMatrix(B, size);

	for (int i = 0; i < size * size; i++)
		cout << B[i] << ' ';
	cout << endl << endl;
	printMatrix(B, size);
	cout << endl;

	degree = 1;
	sum = 0;
	sum = calculateTrace(B, size);
	cout << "Degree: 0\t" << sum << endl << endl;

	while (degree < n)
	{
		B = multMatrix(B, size);
		printMatrix(B, size);
		sum += calculateTrace(B, size);
		cout << "Degree: " << degree << '\t' << sum << endl << endl;
		degree++;
	}
}
void initMatrix(vector<vector<float>>& A, int size)
{
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
			A[i][j] = rand() % 10;
}
void initMatrix(vector<float>& A, int size)
{
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
			A[i * size + j] = rand() % 10;
}
void printMatrix(vector<vector<float>> A, int size)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
			cout << A[i][j] << ' ';
		cout << endl;
	}
}
void printMatrix(vector<float> A, int size)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
			cout << A[i * size + j] << ' ';
		cout << endl;
	}
}
float calculateTrace(vector<vector<float>> A, int size)
{
	float trace = 0;
	for (int i = 0, j = 0; i < size && j < size; ++i, ++j)
		trace += A[i][j];
	return trace;
}
float calculateTrace(vector<float> A, int size)
{
	float trace = 0;
	for (int i = 0, j = 0; i < size && j < size; ++i, ++j)
		trace += A[i * size + j];
	return trace;
}
vector<vector<float>> multMatrix(vector<vector<float>> A, int size)
//matrixes multiplication
{
	vector<vector<float>> B(size, vector<float>(size));
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
		{
			B[i][j] = 0;
			for (int k = 0; k < size; k++)
				B[i][j] += A[i][k] * A[k][j];
		}
	return B;
}
vector<float> multMatrix(vector<float> A, int size)
//matrixes multiplication
{
	vector<float> B(size * size);
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
		{
			B[i * size + j] = 0;
			for (int k = 0; k < size; k++)
				B[i * size + j] += A[i * size + k] * A[k * size + j];
		}
	return B;
}
