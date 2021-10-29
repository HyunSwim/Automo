#include <iostream>
#include <vector>
#include <queue>
#include <string>
#define endl '\n';
using namespace std;

struct Distance {
	vector<int> v;
};

string arr[16][11]; // 0 : 길, 1 : 문, 2 : 아파트, 벽 등 진입 불가 구간
const int x_direction[4] = { -1, 0,1,0 }; // 0 : 북, 1 : 동, 2 : 남, 3 : 서
const int y_direction[4] = { 0,1,0,-1 };
int x = 6;
int y = 10;
Distance root[11][11];
int d[11][11];

void set_root();
void set_load();
void print();
void set_distance();

// 다익스트라 알고리즘을 위한 초기 설정
int number = 11;
int INF = 1000000000;
bool ok[11]; // 방문한 노드
int dis[11]; // 최단 거리

int getSmallIndex() {
	int min = INF;
	int index = 0;
	for (int i = 0;i < number;i++) {
		if (dis[i] < min && !ok[i]) {
			min = dis[i];
			index = i;
		}
	}
	return index;
}

void dijkstra(int start) {
	for (int i = 0;i < number;i++) {
		dis[i] = d[start][i];
	}
	ok[start] = true;
	for (int i = 0;i < number - 2;i++) {
		int current = getSmallIndex();
		ok[current] = true;
		for (int j = 0;j < 11;j++) {
			if (!ok[j]) {
				if (dis[current] + d[current][j] < dis[j]) {
					dis[j] = dis[current] + d[current][j];
				}
			}
		}
	}
}

void set() {
	set_load();
	set_root();
	set_distance();
}

void init() {
	for (int i = 0;i < 16;i++) {
		for (int j = 0;j < 11;j++)
			arr[i][j] = " ";
	}

	for (int i = 0;i < 11;i++) {
		for (int j = 0;j < 11;j++) {
			d[i][j] = INF;
		}
	}

	for (int i = 0;i < 11;i++) {
		ok[i] = false;
	}

	x = 6;
	y = 0;
}

void set_load() {
	arr[6][0] = "S";
	arr[0][10] = arr[1][10] = arr[2][10] = arr[3][8] = arr[3][9] = arr[3][10] = "0";
	arr[4][2] = arr[4][10] = arr[5][2] = arr[5][10] = arr[7][2] = arr[7][5] = arr[7][9] = arr[8][2] = arr[8][9] = arr[8][5] = arr[9][2] = arr[10][2] = arr[10][5] = arr[11][2] = arr[11][5] = arr[12][2] = arr[12][5] = arr[12][6] = arr[12][7] = arr[13][3] = arr[13][2] = arr[13][4] = arr[13][5] = "0";
	for (int i = 1;i < 11;i++)
		arr[6][i] = "0";
	for (int i = 5;i < 10;i++)
		arr[9][i] = "0";

	arr[8][1] = "a"; arr[11][1] = "b"; 	arr[4][3] = "c"; 	arr[8][3] = "d"; 	arr[14][3] = "e";	arr[0][9] = "f";	arr[4][8] = "g";	arr[7][7] = "h";	arr[10][7] = "i";	arr[13][7] = "j";
}

// 경로 저장
void set_root() {
	// start -> 101
	root[0][1].v.push_back(1);
	root[0][1].v.push_back(1);
	root[0][1].v.push_back(2);
	root[0][1].v.push_back(2);

	// start -> 104
	root[0][4].v.push_back(1);
	root[0][4].v.push_back(1);
	root[0][4].v.push_back(2);
	root[0][4].v.push_back(2);

	// start -> 108
	root[0][8].v.push_back(1);
	root[0][8].v.push_back(1);
	root[0][8].v.push_back(1);
	root[0][8].v.push_back(1);
	root[0][8].v.push_back(1);
	root[0][8].v.push_back(1);
	root[0][8].v.push_back(1);

	// start -> 103
	root[0][3].v.push_back(1);
	root[0][3].v.push_back(1);
	root[0][3].v.push_back(0);
	root[0][3].v.push_back(0);

	// start -> 109
	root[0][9].v.push_back(1);
	root[0][9].v.push_back(1);
	root[0][9].v.push_back(1);
	root[0][9].v.push_back(1);
	root[0][9].v.push_back(1);
	root[0][9].v.push_back(2);
	root[0][9].v.push_back(2);
	root[0][9].v.push_back(2);
	root[0][9].v.push_back(1);
	root[0][9].v.push_back(1);

	// start -> 110
	root[0][10].v.push_back(1);
	root[0][10].v.push_back(1);
	root[0][10].v.push_back(1);
	root[0][10].v.push_back(1);
	root[0][10].v.push_back(1);
	root[0][10].v.push_back(2);
	root[0][10].v.push_back(2);
	root[0][10].v.push_back(2);
	root[0][10].v.push_back(2);
	root[0][10].v.push_back(2);
	root[0][10].v.push_back(2);
	root[0][10].v.push_back(1);
	root[0][10].v.push_back(1);

	// 101 -> 102
	root[1][2].v.push_back(2);
	root[1][2].v.push_back(2);
	root[1][2].v.push_back(2);

	// 101 -> 103
	root[1][3].v.push_back(1);
	root[1][3].v.push_back(0);
	root[1][3].v.push_back(0);
	root[1][3].v.push_back(0);
	root[1][3].v.push_back(0);

	// 101 -> 104
	root[1][4].v.push_back(1);
	
	// 102 -> 104
	root[2][4].v.push_back(1);
	root[2][4].v.push_back(0);
	root[2][4].v.push_back(0);
	root[2][4].v.push_back(0);

	// 102 -> 105
	root[2][5].v.push_back(1);
	root[2][5].v.push_back(2);
	root[2][5].v.push_back(2);
	root[2][5].v.push_back(1);

	// 103 -> 104
}// 0 : 북, 1 : 동, 2 : 남, 3 : 서

void set_distance() {
	for (int i = 0;i < 11;i++) {
		d[i][i] = 0;
	}
	d[0][1] = d[1][0] = 5;
	d[0][3] = d[3][0] = 5;
	d[0][4] = d[4][0] = 5;
	d[0][8] = d[8][0] = 8;
	d[0][9] = d[9][0] = 11;
	d[0][10] = d[10][0] = 14;
	d[1][2] = d[2][1] = 4;
	d[1][3] = d[3][1] = 6;
	d[1][4] = d[4][1] = 2;
	d[1][8] = d[8][1] = 9;
	d[1][9] = d[9][1] = 12;
	d[2][4] = d[4][2] = 5;
	d[2][5] = d[5][2] = 5;
	d[3][4] = d[4][3] = 6;
	d[3][8] = d[8][3] = 9;
	d[3][9] = d[9][3] = 12;
	d[3][10] = d[10][3] = 15;
	d[4][8] = d[8][4] = 9;
	d[4][9] = d[9][4] = 12;
	d[5][8] = d[8][5] = 13;
	d[5][9] = d[9][5] = 10;
	d[5][10] = d[10][5] = 7;
	d[6][7] = d[7][6] = 7;
	d[6][8] = d[8][6] = 11;
	d[6][9] = d[9][6] = 14;
	d[7][8] = d[8][7] = 10;
	d[7][9] = d[9][7] = 13;
	d[8][9] = d[9][8] = 9;
	d[8][10] = d[10][8] = 11;
	d[9][10] = d[10][9] = 9;
}

void move(int num) {
	x += x_direction[num];
	y += y_direction[num];
}

void search(int start, int value, int num) {
	for (int i = 0;i < root[start][value].v.size();i++) {
		num++;
		move(root[start][value].v[i]);
		arr[x][y] = to_string(num);
	}

	print();
	cout << endl;
	cout << " 걸린 시간 : " << num + 1 << endl;
}

void print() {
	for (int i = 0;i < 16;i++) {
		for (int j = 0;j < 11;j++) {
			cout << arr[i][j];
			if(arr[i][j].size()==1)
				cout << " ";
		}
		cout << endl;
	}
}

int main() {
	init();
	set();
	dijkstra(0); // 파라미터에 시작값
	for (int i = 0;i < number;i++) {
		cout << dis[i] << " ";
	}
	cout << endl;

	//while (1) {
	//	/*init();
	//	set();
	//	int value;
	//	int value2;

	//	print();
	//	cin >> value >> value2;

	//	search(0, value, 0);
	//	search(value, value2, 0);
	//	return 0;*/
	//}
}
// 00 01 02 
// 10 11 12
// 20 21 22
// stl = to_string(i); : int -> string
// stoi() : string -> int

// 보안할 점
// 0. 지도 매핑 꾸준히(이동경로, 최단거리 저장)
// 1. 지도 매핑 다시하기(목적지와 길이 모호함, 좀 더 이쁘게(GPU 사용해서))
// 2. 도착하면 도착지의 알파벳 대문자로