#include <iostream>
#include <fstream>
#include <vector>
#include <string>


using namespace std;

const int HEADER_ROW = 0;
const int TOTAL_COLS = 9;
const char DELIM = ',';
const char NEW_LINE = '\n';
const string INVALID_MSG = "\ninvalid response\n";

enum LABELS
{
	ID = 0,
	ALIAS = 1,
	HOST_ID = 2,
	OS = 3,
	MEM_TOTAL = 4,
	MEM_FREE = 5,
	DISK_TOTAL = 6,
	DISK_FREE = 7,
	vHOST = 8
};

vector<string> LABEL_NAMES =
{
	"ID,",
	"Alias,",
	"Host ID,",
	"OS,",
	"Mem Total,",
	"Mem Free,",
	"Disk_Total,",
	"Disk Free,",
	"vHost?\n"
};

const char Y = 'Y';
const char N = 'N';
const char INVALID = 'I';

void clear_stream() 
{
	cin.ignore(10000, '\n');
	cin.clear();
}

void out_header_row(vector<vector<string>>table)
{
	std::cout << "Entered";
	if (table.size() == 0)
	{
		std::cout << "\ntable not initialized\n";
	}
	else
	{
		for (int i = 0; i < TOTAL_COLS; i++)
		{
			std::cout << table[HEADER_ROW][i] << " ";
		}
		cout << "\n";
	}
}


void add_header_row(vector<vector<string>>& table)
{
	if (table.empty())
	{
		// add new vector, representing row
		// (specifically the first [header] row
		table.push_back(LABEL_NAMES);
		// checking num of rows to ensure empty table
		cout << "\nnumber of rows: " << table.size() << "\n";
	}
	else
	{
		cout << "\nfile has already been initialized!\n";
	}
}

void msg_input_complete()
{
	cout << "\ninput complete\n";
}

void no_file_found()
{
	cout << "\nno file found\n";
}

void file_found()
{
	cout << "\nfile found\n";
}

void creating_header()
{
	cout << "\ninitializing new log...\n";
	cout << "\nadding header...\n";
}

void build_table(int size, const char* c_arr, vector<vector<string>>& table, int& row)
{
	string str;
	vector<string> str_vect;
	int str_count = 0;

	for (int i = 0; i < size; i++)
	{
		char curr_char = c_arr[i];
		//for debug:
		//cout << curr_char;

		if (curr_char == DELIM)
		{
			//for debug:
			//cout << "DELIM FOUND\n";
			str += curr_char;
			str_vect.push_back(str);
			str = "";
			//for debug:
			//cout << str_vect[str_count];
			str_count++;
			//for debug:
			//cout << "string count: " << str_count << endl;
		}

		else if (i == size - 1)
		{
			//for debug:
			//cout << "str c: " << str_count << endl;
			str += curr_char;

			str += '\n';
			//for debug:
			//cout << "NEW LINE\n";
			str_vect.push_back(str);
			table.push_back(str_vect);
			str_vect.clear();
			str = "";
			//for debug:
			//cout << table[row][0] << '\n';
			str_count = 0;
			row++;
		}

		else
		{
			str += curr_char;
			//for debug:
			//cout << "curr string: ";
			//cout << str << '\n';
		}
	}
}

void display_table(vector <vector<string>>table)
{
	for (int i = 0; i < table.size(); i++)
	{
		for (int j = 0; j < table[i].size(); j++)
		{
			cout << table[i][j];
		}
		cout << '\n';
	}
	
}

void split_row(vector<string>& entry, vector<vector<string>>table, int row)
{
	int invalid = -1;
	int user_input = invalid;
	int index = row - 1;

	entry.clear();

	do 
	{
		cout << "\nChoose row: ";
		cin >> user_input;

		if (user_input > index)
		{
			cout << "\nInvalid row\n";
			user_input = invalid;
		}
		else if (user_input == 0)
		{
			cout << "\ncan't edit header\n";
			user_input = invalid;
		}
		else 
		{
			for (int i = 0; i < TOTAL_COLS; i++)
			{
				entry.push_back(table[index][i]);
			}
		}
	} while (user_input == invalid);
}

void remove_comma(string &str)
{
	for (size_t i = 0; i < str.length(); ++i)
	{
		if (str[i] == ',')
		{
			str.erase(i--, 1);
		}
	}
	// source: https://stackoverflow.com/questions/19138983/c-remove-punctuation-from-string
}


void edit_data(vector<string>& entry, int index)
{
	string user_input;
	char user_char;
	
	do
	{
		clear_stream();
		string new_data;
		cout << "\nCurrent data: " << entry[index] << "\n";
		cout << "Enter new data: ";
		getline(cin, new_data);		
		cout << "\nNew Data: " << new_data;
		cout << "\nLook good? Y or N\n";
		cin >> user_input;
		user_char = toupper(user_input[0]);
		switch (user_char)
		{
		case(Y):
			cout << "\nupdating " << entry[index] << "to " << new_data << endl;
			remove_comma(new_data);
			if (index < entry.size() - 1)
			{
				new_data += ',';
			}
			else
			{
				new_data += '\n';
			}
			entry[index] = new_data;
			break;
		default:
			user_char = N;
		}
	} while (user_char == N);
}

void edit_entry(vector<string>& entry)
{
	int user_input = -1;
	string new_entry;
	int invalid_num = -1;
	const int quit = 11;
	const int ref = 0;

	cout << typeid(user_input).name();
	clear_stream();

	for (int i = 0; i < entry.size(); i++)
	{
		cout << entry[i] << " ";
	}
	do
	{
		cout << "\nWhich field needs an edit?\n";

		for (int i = 0; i < LABEL_NAMES.size(); i++)
		{
			LABEL_NAMES[i].erase(remove(LABEL_NAMES[i].begin(), LABEL_NAMES[i].end(), ','));
			cout << i << ". " << LABEL_NAMES[i] << ": " << entry[i] << '\n';
		}

		cout << "11. quit\n";
		
		cin >> user_input;
		
		while (typeid(user_input) != typeid(ref))
		{
			clear_stream();
			cout << "\ninvalid repsonse\n";
			cin >> user_input;
		}

		switch (user_input)
		{
		case(ID):
			edit_data(entry, ID);
			break;
		case(ALIAS):
			edit_data(entry, ALIAS);
			break;
		case(HOST_ID):
			edit_data(entry, HOST_ID);
			break;
		case(OS):
			edit_data(entry, OS);
			break;
		case(MEM_TOTAL):
			edit_data(entry, MEM_TOTAL);
			break;
		case(MEM_FREE):
			edit_data(entry, MEM_FREE);
			break;
		case(DISK_TOTAL):
			edit_data(entry, DISK_TOTAL);
			break;
		case(DISK_FREE):
			edit_data(entry, DISK_FREE);
			break;
		case(vHOST):
			edit_data(entry, vHOST);
			break;
		case(quit):
			break;
		default:
			user_input = invalid_num;
		}

	} while (user_input == invalid_num || user_input != quit);
}

vector<string> add_entry()
{
	string user_input;
	char user_char;
	vector<string> entry;
	// clear stream from prev inputs
	clear_stream();
	
	for (int i = 0; i < TOTAL_COLS; i++)
	{
		string user_input = "";
		LABEL_NAMES[i].erase(remove(LABEL_NAMES[i].begin(), LABEL_NAMES[i].end(), ','));
		LABEL_NAMES[i].erase(remove(LABEL_NAMES[i].begin(), LABEL_NAMES[i].end(), '\n'));
		cout << LABEL_NAMES[i] << ": ";
		
		getline(cin, user_input);
		remove_comma(user_input);
		if (i < TOTAL_COLS - 1)
		{
			user_input += ',';
		}
		entry.push_back(user_input);
	}

	for (int i = 0; i < entry.size(); i++)
	{
		cout << entry[i] << '\n';
	}
	do
	{
		cin.clear();
		cout << "\nLook good? Enter Y or N\n";
		cin >> user_input;
		user_char = toupper(user_input[0]);
		switch (user_char)
		{
		case(Y):
			break;
		case(N):
			edit_entry(entry);
			break;
		default:			
			user_char = INVALID;
			if (user_char != N)
			{
				std::cout << INVALID_MSG;
			}
			
		}
	} while (user_char == INVALID);
	return entry;
}

char menu()
{
	string user_input;
	char user_char;
	char output;

	do
	{
		cin.clear();
		cout << "Select an Option:\n";

		cout << "A. view VM log\nB. add new entry\n";
		cout << "C. edit entry\nD. write temp.csv file\n";
		cout << "E. restore log\nF. save and quit\n";

		cin >> user_input;
		user_char = toupper(user_input[0]);


		switch (user_char)
		{
		case('A'):
			break;
		case('B'):
			break;
		case('C'):
			break;
		case('D'):
			break;
		case('E'):
			break;
		case('F'):
			break;
		default:
			user_char = INVALID;
			cout << INVALID_MSG;
		}
	} while (user_char == INVALID);
	return user_char;

}

/*void write_file(string file_name, vector<vector<string>> table)
{
	ifstream write_file;

	write_file.open(file_name);

	for (int i = 0; i < table.size(); i++)
	{
		for (int j = 0; j < table[i].size(); j++)
		{
			write_file >> table[i][j];
		}
	}
	write_file.close();

}*/

int main()
{

	// if the file is empty:
	// add header row:
	// ID, Alias, HostID, OS, Mem Total, Mem Free, Disk Total, Disk Free, vHost

	// if the file is not empty:
	// open input file
	// display contents
	// to count number of current entries

	//display menu
	// user can add a new entry
	// user can edit entries on main list (dir)
	// user can view VMs for a given host (hostID)
	// (TODO) need a way to edit across files (one entry edit changes across entire log)
	// (TODO) add header file of constants
	//begin prompt to enter VM info

	//NOTE: when user edits log, it will update a local file
	//Prompting save will write to the main VM LOG via bash script

	// have a separate bash script to add and commit to git
	// have a separate bash script to push to GitHub

	// create log to track Virtual Machines and their hosts
	vector<vector<string>> vm_log;
	// vector to write rows of the vm_log to
	vector<string> entry;
	// doc to write to
	ofstream write_log;
	// doc to read from
	ifstream read_log;
	// main vm_log to initalize from
	ifstream parent_doc("../vm_log.csv");
	// string that will read a line (string) of a file
	string line;
	// char array that will break down a line into its chars
	const char* data;
	// tracking row count to use as an index
	int row = 0;
	// does the parent doc exist?
	bool parent_good = parent_doc.good();
	// menu choices
	const char view = 'A';
	const char add = 'B';
	const char edit = 'C';
	const char write = 'D';
	const char restore = 'E';
	const char quit = 'F';
	// user input variable
	char user_choice;

	// checking for file existence
	if (parent_good)
	{
		file_found();
		while (getline(parent_doc, line))
		{
			//cout << line << "\n";
			data = line.c_str();
			build_table(strlen(data), data, vm_log, row);
		}
		display_table(vm_log);
	}
	else
	{
		no_file_found();
		creating_header();
		add_header_row(vm_log);
		row++;
		msg_input_complete();
		display_table(vm_log);
	}
	//create temp file (protects parent doc)
	write_log.open("temp.csv");
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < TOTAL_COLS; j++)
		{
			write_log << vm_log[i][j];
		}
	}
	write_log.close();
	//create back up file (restore table to OG state)
	write_log.open("backup_log.csv");
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < TOTAL_COLS; j++)
		{
			write_log << vm_log[i][j];
		}
	}
	write_log.close();
	string choice;
	char letter = INVALID;
	while (letter == INVALID)
	{
		do
		{
			cin.clear();
			user_choice = menu();
			switch (user_choice)
			{
			case (view):
				display_table(vm_log);
				break;
			case (add):
				vm_log.push_back(add_entry());
				row++;
				break;
			case (edit):
				split_row(entry, vm_log, row);
				edit_entry(entry);
				break;
			case (write):
				cout << "writing..." << endl;
				write_log.open("temp.csv");
				for (int i = 0; i < row; i++)
				{
					for (int j = 0; j < TOTAL_COLS; j++)
					{
						write_log << vm_log[i][j];
					}
				}
				write_log.close();
				cout << "\ntemp.csv updated" << endl;
				break;
			case (restore):
				do
				{
					cout << "\ncurrent table:\n";
					display_table(vm_log);
					cout << "\nrestore table to original state? Y or N\n";
					cout << "\n(type N to return to main menu)\n";
					cin >> choice;
					letter = toupper(choice[0]);
					if (letter != Y) {}
					else
					{
						vm_log.clear();
						read_log.open("backup_log.csv");
						while (getline(read_log, line))
						{
							//cout << line << "\n";
							data = line.c_str();
							build_table(strlen(data), data, vm_log, row);
						}
						cout << "\nrestore complete\n";
						cout << "\nupdated table:\n";
						display_table(vm_log);
						break;
					}
				} while (letter != N && letter != Y);
				break;
			case (quit):
				do
				{
					cout << "\n-- Make sure to WRITE before SAVING! --\n";
					cout << "\nType Y to copy temp.csv to parent doc and quit\n";					
					cout << "\n(type N to quit without saving)\n";
					cout << "\n(type " << INVALID << " to return to main menu)\n";
					cin >> choice;
					letter = toupper(choice[0]);
					if (letter == Y)
					{
						system("copy_log.sh");
						break;
					}
				} while (letter != INVALID);
				break;
			}
		} while (user_choice != quit);
	}
	return 0;
}




	
