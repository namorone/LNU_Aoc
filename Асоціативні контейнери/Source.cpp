#include <fstream>
#include<iostream>//�� � ���������� �������+
#include<map>
#include<string>
#include <Windows.h>

using namespace std;

/*2. � ���������� ���� ������ ������ ��� ��� ������� �������� (���������, ����.� ���.). ���� ����� ������ ���� ������� ���������. 
- ��������� �������� ���� (�������) 
- ������ ��� � ����� 
- ������� � ����1 ��� ���������� �� �������� ������ ��� ��� (����.� ���. �  ���.-����.). ���� ����� �� ������� ������� ���������, �� ������� ����� (���� ���) � ��� �� ������� ���������. 
- ������� � ����2 �������� �������� ������ ���.   
*/

class Vocabulary
{
private:
    multimap<string, string> EN_and_UKR;
    multimap<string, string> UKR_and_EN;
public:
    Vocabulary() {};
    void input_for_EN_and_UKR(ifstream& file)
    {
        while (!file.eof())//����� ���� 
        {
            string eng_word, ukr_word;
            file >> eng_word >> ukr_word;
            if (eng_word != "" && ukr_word != "")
            {
                EN_and_UKR.emplace(eng_word, ukr_word);
            }
        }
    }
    void input_for_UKR_and_EN(ifstream& file)
    {
        while (!file.eof())//����� ���� 
        {
            string eng_word, ukr_word;
            file >> eng_word >> ukr_word;
            if (eng_word != "" && ukr_word != "")
            {
                UKR_and_EN.emplace(ukr_word, eng_word);
               
            }
        }
    }
    void print_(ofstream& file)
    {
        multimap <string, string>::iterator iter;
        for (iter = EN_and_UKR.begin(); iter != EN_and_UKR.end(); )
        {
            pair <multimap<string, string>::iterator, multimap<string, string>::iterator> ret;
            ret = EN_and_UKR.equal_range(iter->first);
            file << iter->first << " ---> ��������:";
            size_t cycle = 0;
            for (multimap<string, string>::iterator it = ret.first; it != ret.second; iter++)
            {
                if (it != ret.first && it != ret.second)
                {
                    if (it == ++ret.first)
                    {
                        file << " ";
                        --ret.first;
                    }
                }

                file << ' ' << it->second;

                ++it;
                cycle++;

                if (cycle != 1 && it != ret.second)
                    file << ',';


            }
            file << '\n';
        }
        file << "_________________________________________________________________"<<'\n'; 
       
        for (iter = UKR_and_EN.begin(); iter != UKR_and_EN.end(); )
        {
            pair <multimap<string, string>::iterator, multimap<string, string>::iterator> ret;
            ret = UKR_and_EN.equal_range(iter->first);
            file << iter->first << " ---> ��������:";
            size_t cycle = 0;
            for (multimap<string, string>::iterator it = ret.first; it != ret.second; iter++)
            {
                if (it != ret.first && it != ret.second)
                {
                    if (it == ++ret.first)
                    {
                        file << " ";
                        --ret.first;
                    }
                }

                file << ' ' << it->second;

                ++it;
                cycle++;

                if (cycle != 1 && it != ret.second)
                    file << ',';


            }
            file << '\n';
        }
    }
    
    void print_2(ofstream& file)
    {
        for (auto it = EN_and_UKR.begin(); it != EN_and_UKR.end();++it)
        {
            file << it->second << endl;
        }
    }
};
int main()
{
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    ifstream infile("Infile.txt");
    ifstream infile2("Infile2.txt");
    ofstream outfile1("File1.txt");
    ofstream outfile2("File2.txt");

    Vocabulary vocabulary;
    vocabulary.input_for_EN_and_UKR(infile);
    infile.close();
    //ifstream infile("Infile.txt");
    vocabulary.input_for_UKR_and_EN(infile2);
    vocabulary.print_(outfile1);
    vocabulary.print_2(outfile2);
      
      cout << "\n See in files 1 and 2 for the result of program \n";
      
  // infile.close();
    infile2.close();
    outfile1.close();
    outfile2.close();
    return 0;
}