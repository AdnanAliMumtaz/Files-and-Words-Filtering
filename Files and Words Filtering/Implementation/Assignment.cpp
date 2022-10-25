//Name:                 Adnan Ali Mumtaz
//Student ID Number:    20862007 / CE
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

const int MAX_Words = 10000;
int Occurence[MAX_Words];
string RepeatingWord[MAX_Words];
vector <string> sortedtext;

string ToLower(string myString)//Funtions to lower case strings.
{
	string lowerString;
	for (auto c : myString)  lowerString += tolower(c);
	return lowerString;
}

class File {//Base Class for reading, writing, displaying file words and counting the frequency.
private:
	string word;
public:
	vector <string> textWords; //Vector to store all the content from files for comparison etc.
	int FrequencyIndex = 0;

	File(string txtname)//Constructor for reading files.
	{
		cout << "-----------------------------------------------" << txtname << "-----------------------------------------------\n";
		
		ifstream file(txtname);
		while (!file.eof())
		{
			if (!file.eof())
			{
				file >> word;
				cout << word << " ";
				textWords.push_back(word);//Words are being pushed back into textfile vector.
			}
		}
		file.close();
		cout << endl;
	}

	void Writefile(string name, vector <string> textwords)//Code for writing into the filtered files.
	{
		ofstream file(name);
		for (int i = 0; i < textwords.size(); ++i)
		{
			file << textwords[i] << " ";
		}
		file.close();
	}

	void FrequencyCounter(vector <string> FrequencyWord) {//Method that calculates the Frequency of words.

		for (int a = 0; a < FrequencyWord.size(); a++)
		{
			FrequencyWord[a] = ToLower(FrequencyWord[a]);//Converts all letters into the small letters.

			//Loop that will look for any punctuations or '-' and '/' to erase and insert empty string.
			for (int i = 0; i < FrequencyWord[a].size(); i++)
			{
				if (ispunct(FrequencyWord[a][i]) || FrequencyWord[a][i] == '-' || FrequencyWord[a][i] == '/')
				{
					FrequencyWord[a].erase(i--, 1);//Erases any punctuations etc.
					FrequencyWord[a].insert(i + 1, " ");//Add spaces on the places of punctuations.

					stringstream ssin(FrequencyWord[a]);
					while (ssin.good())//Only reads string without space. E.g Word-and would be read as "Word" and "and".
					{
						ssin >> FrequencyWord[a];
					}
				}
			}

			/* Code below, Learned frequency counting from here: www.youtube.com/watch?v=ejrdnpJkdys */

			bool hasAppeared = false;
			for (int i = 0; i < FrequencyIndex; i++)
			{
				if (FrequencyWord[a] == RepeatingWord[i])//'RepeatingWords' are words that have had been counted at least once.
				{
					Occurence[i]++;//Increment Occurence for specific element in array.
					hasAppeared = true;
				}
			}
			if (!hasAppeared)//If hasAppeared isn't "true", word will be assinged to 'RepeatingWords variable'.
			{
				RepeatingWord[FrequencyIndex] = FrequencyWord[a];
				Occurence[FrequencyIndex] = 1; //Occurence is being set to '1', as word has been assigned to 'RepeatingWords' and counter as 1.
				FrequencyIndex++;//Incremented. Whole process would repeat for next word and will be assinged to next element in array.
			}
		}

		cout << endl;
		cout << "----TOP 10 FREQUENCANT WORDS----\n";
		for (int a = 0; a < 10; a++)
		{
			int Highest_Count = Occurence[0];
			int Highest_Index = 0;
			for (int i = 1; i < FrequencyIndex; i++)
			{
				if (Occurence[i] > Highest_Count)//Loop goes through the whole 'Occurence' array to find highest value of and assign to topCount.
				{
					Highest_Count = Occurence[i];
					Highest_Index = i;//Assigning topindex to 'i', to keep track of topCount array's index.
				}
			}
			Occurence[Highest_Index] = 0;//Occurence reset to '0'. So, loop can find the next most repeated word.
			FrequencyWord[a] = RepeatingWord[Highest_Index];//RepeatingWord with topindex is assinged to the FrequencyWord.

			cout << "-> '" << FrequencyWord[a] << "' found '" << Highest_Count << "' times." << endl;//Outputting Top 10 Words.
		}
	}
};

class Comparison : public File {//Child class of 'File'.
public:
	Comparison(string txt) :File(txt) {}//Inheriting Contructor from base class.

	//Method that compares two files, replaces midlle characters with "*" and writes filtered text into filter-files.
	void comparison(vector <string> banned_Words, vector <string> textFile, string FilterFile)  
	{
		//Calling Frequency Counter Method for specific textfile.
		FrequencyCounter(textFile);

		cout << "\n";
		cout << "----Comparison----\n";
		int IndexFinder = -1; //Set on default false value, which means "Not Found".
		for (int i = 0; i < banned_Words.size(); i++)//Comparison of files.
		{
			int counter = 0;
			for (int j = 0; j < textFile.size(); j++)
			{
				do {
					//Stores Index Finder value, Lowers the letters in file and compares string with substrings through the textfiles.
					IndexFinder = ToLower(textFile[j]).find(banned_Words[i], IndexFinder + 1);//Keeps finding substrings by adding +1 till forloop finishes.
					if (IndexFinder != -1)
					{
						counter++;
						textFile[j].replace(IndexFinder + banned_Words[i].size() / 2, 1, string(1, '*'));//Replaces the middle of founded word with "*".
						sortedtext.push_back(textFile[j]);//Pushing back the sorted words.
					}
				} while (IndexFinder != -1);//Repeating loop as long as IndexFinder is not False (-1).
			}

			//Outputting how many times each banned word has appeared in a specific file.
			cout << "-> '" << banned_Words[i] << "' found '" << counter << "' times." << endl;

			Writefile(FilterFile, textFile);//Code for writing Filtered words into the into the files.
		}
	}
};

int main()
{
	//Banned Words--------
	File bannedword("banned.txt");

	//Text File 1--------
	Comparison text1("text1.txt");
	text1.comparison(bannedword.textWords, text1.textWords, "text1Filtered.txt");

	//Text File 2--------
	Comparison text2("text2.txt");
	text2.comparison(bannedword.textWords, text2.textWords, "text2Filtered.txt");

	//Text File 3--------
	Comparison text3("text3.txt");
	text3.comparison(bannedword.textWords, text3.textWords, "text3Filtered.txt");

	//Text File 4--------
	Comparison text4("text4.txt");
	text4.comparison(bannedword.textWords, text4.textWords, "text4Filtered.txt");

	text4.Writefile("sorted.txt",sortedtext);//Sorted words to be written in the 'sorted.txt'.
}
