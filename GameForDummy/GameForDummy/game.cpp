#include <iostream>
#include <random>
#include <ctime>
#include <stdlib.h>
#include <conio.h>
#include <vector>

using namespace std;

int get_score(vector<char> a, int b)
{
	for (int i = 0; i < 9; i++)
		if (a[i] == '-' and a[i + 1] == 'X')
			b++;
	return b;
}

int game_over(vector<char> a)
{
	if (a[0] == 'X') return 0;
	else return -1;
}

vector<char> bullet(vector<char> a)
{
	if (a[9] == '-') a[9] = ' ';
	for (int i = 8; i > 0; i--)
		if (a[i] == '-') { a[i + 1] = '-'; a[i] = ' '; }
	return a;
}

vector<char> move_enemy(vector<char> a)
{
	for (int i = 1; i < 10; i++)
		if (a[i] == 'X' and a[i - 1] != '-') { a[i - 1] = 'X'; a[i] = ' '; }
	return a;
}

void field(vector <char> a)
{
	for (int i = 0; i < 10; i++)
		cout << a[i] << ' ';
}

int main()
{
	for (char menu, selected = 1;;)
	{
		if (selected == 1)
		{
			cout << ">1.Start" << endl;
			cout << " 2.Difficult" << endl;
			cout << " 3.Exit" << endl;
		}
		else if (selected == 2)
		{
			cout << " 1.Start" << endl;
			cout << ">2.Difficult" << endl;
			cout << " 3.Exit" << endl;
		}
		else
		{
			cout << " 1.Start" << endl;
			cout << " 2.Difficult" << endl;
			cout << ">3.Exit" << endl;
		}
		menu = _getch();
		if (menu == 'w' and selected != 1)
			selected--;
		else if (menu == 's' and selected != 3)
			selected++;
		else if (menu == 'd' and selected == 1)
		{
			system("cls");
			break;
		}
		else if (menu == 'd' and selected == 2)
		{
			for (char diffucult, selected_ = 1;;)
			{
				system("cls");
				if (selected_ == 1)
				{
					cout << ">Are you sure?" << endl;
					cout << " Hard" << endl;
					cout << " Normal" << endl;
					cout << " Easy" << endl;
				}
				else if (selected_ == 2)
				{
					cout << " Are you sure?" << endl;
					cout << ">Hard" << endl;
					cout << " Normal" << endl;
					cout << " Easy" << endl;
				}
				else if (selected_ == 3)
				{
					cout << " Are you sure?" << endl;
					cout << " Hard" << endl;
					cout << ">Normal" << endl;
					cout << " Easy" << endl;
				}
				else if (selected_ == 4)
				{
					cout << " Are you sure?" << endl;
					cout << " Hard" << endl;
					cout << " Normal" << endl;
					cout << ">Easy" << endl;
				}
				diffucult = _getch();
				if (diffucult == 'w' and selected_ != 1)
				{
					selected_--;
				}
				else if (diffucult == 's' and selected_ != 4)
				{
					selected_++;
				}
				else if (diffucult == 'd' and selected_ == 1)
				{
					system("cls");
					//
					break;
				}
				else if (diffucult == 'd' and selected_ == 2)
				{
					system("cls");
					//
					break;
				}
				else if (diffucult == 'd' and selected_ == 3)
				{
					system("cls");
					//
					break;
				}
				else if (diffucult == 'd' and selected_ == 4)
				{
					system("cls");
					//
					break;
				}
			}
		}
		else if (menu == 'd' and selected == 3) return 0;

		system("cls");
	}


	int x = 6, enemy = 4, score = 0;
	vector <char> q(10), w(10), e(10), r(10), t(10), y(10);
	q[0] = '>';
	w[0] = '|';
	e[0] = '|';
	r[0] = '|';
	t[0] = '|';
	y[0] = '|';
	char get;
	mt19937 gen(time(0));
	uniform_int_distribution<> uid(1, 6);
	uniform_int_distribution<> aid(1, 2);
	for (;;)
	{
		field(q);
		cout << "  ___" << endl;
		field(w);
		cout << "|\\ _ /| S" << endl;
		field(e);
		cout << "| | | | C" << endl;
		field(r);
		if (score > 9 and score < 100) cout << "|-" << score << " -| O" << endl;
		else if (score < 10) cout << "|- " << score << " -| O" << endl;
		else cout << "|-" << score << "-| O" << endl;
		field(t);
		cout << "| |_| | R" << endl;
		field(y);
		cout << "|/___\\| E" << endl;


		enemy = game_over(q);
		if (enemy == 0)
		{
			cout << "Game Over" << endl;
			break;
		}
		enemy = game_over(w);
		if (enemy == 0)
		{
			cout << "Game Over" << endl;
			break;
		}
		enemy = game_over(e);
		if (enemy == 0)
		{
			cout << "Game Over" << endl;
			break;
		}
		enemy = game_over(r);
		if (enemy == 0)
		{
			cout << "Game Over" << endl;
			break;
		}
		enemy = game_over(t);
		if (enemy == 0)
		{
			cout << "Game Over" << endl;
			break;
		}
		enemy = game_over(y);
		if (enemy == 0)
		{
			cout << "Game Over" << endl;
			break;
		}

		if (score > 99)
		{
			cout << "You Win" << endl;
			break;
		}

		for (;;)
		{
			get = _getch();
			if ((get == 'w' and x != 6) or (get == 's' and x != 1) or get == 'd')
			{
				break;
			}
		}
		if (get == 'w') x++;
		else if (get == 's') x--;
		if (x == 1) { y[0] = '>'; t[0] = '|'; }
		else if (x == 2) { t[0] = '>'; y[0] = '|'; r[0] = '|'; }
		else if (x == 3) { r[0] = '>'; e[0] = '|'; t[0] = '|'; }
		else if (x == 4) { e[0] = '>'; w[0] = '|'; r[0] = '|'; }
		else if (x == 5) { w[0] = '>'; q[0] = '|'; e[0] = '|'; }
		else if (x == 6) { q[0] = '>'; w[0] = '|'; }

		if (get == 'd')
		{
			if (x == 1 and y[1] == 'X') { y[1] = '-'; score++; }
			else if (x == 1) y[1] = '-';
			else if (x == 2 and t[1] == 'X') t[1] = '-', score++;
			else if (x == 2) t[1] = '-';
			else if (x == 3 and r[1] == 'X') r[1] = '-', score++;
			else if (x == 3) r[1] = '-';
			else if (x == 4 and e[1] == 'X') e[1] = '-', score++;
			else if (x == 4) e[1] = '-';
			else if (x == 5 and w[1] == 'X') w[1] = '-', score++;
			else if (x == 5) w[1] = '-';
			else if (x == 6 and q[1] == 'X') q[1] = '-', score++;
			else if (x == 6) q[1] = '-'; // else
		}

		q = move_enemy(q);
		w = move_enemy(w);
		e = move_enemy(e);
		r = move_enemy(r);
		t = move_enemy(t);
		y = move_enemy(y);

		score = get_score(q, score);
		score = get_score(w, score);
		score = get_score(e, score);
		score = get_score(r, score);
		score = get_score(t, score);
		score = get_score(y, score);

		q = bullet(q);
		w = bullet(w);
		e = bullet(e);
		r = bullet(r);
		t = bullet(t);
		y = bullet(y);
		enemy = aid(gen);
		if (enemy == 1)
		{
			enemy = uid(gen);
			if (enemy == 1) y[9] = 'X';
			else if (enemy == 2) t[9] = 'X';
			else if (enemy == 3) r[9] = 'X';
			else if (enemy == 4) e[9] = 'X';
			else if (enemy == 5) w[9] = 'X';
			else if (enemy == 6) q[9] = 'X';
		}
		system("cls");
	}
}