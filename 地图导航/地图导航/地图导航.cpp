#include <iostream>
#include <fstream>
#include <string>

using namespace std;

#define N  25

bool isPeak(const double grid[][N], int r, int c);
bool isValley(const double grid[][N], int i, int j);
void extremes(const double grid[][N], int row, int column);

int main(){

	int nrows, ncols;
	double map[N][N];
	string filename;
	ifstream file;

	cout <<"�������ļ���.\n";
	cin  >> filename;

	file.open(filename.c_str());
	if(file.fail()){
		cerr<<"�������ļ�����.\n";
		exit(1);
	}

	file>>nrows>>ncols;

	if(nrows > N || ncols > N){
		cerr<<"����̫�󣬵�������.\n";
		exit(1);
	}

	//�������ļ������ݵ�����
	for(int i=0; i<nrows; ++i){
		for(int j=0; j<ncols; ++j){
			file>>map[i][j];
		}
	}

	int total_peaks = 0;

	//�жϲ���ӡ��ֵλ��
	for(int i=1;i<nrows-1; ++i){
		for(int j=1;j<ncols-1; ++j){
			if(isPeak(map, i, j)){
				cout<<"��ֵ��������: "<<i<<" ��:"<<j<<endl;
				total_peaks++;
			}else if(isValley(map, i, j)){
				cout<<"�ȵ��������: "<<i<<" ��:"<<j<<endl;
			}
		}
	}

	//��ӡ���ε����ֵ����Сֵ���Լ��������ڵ�λ��
	extremes(map, nrows, ncols);

	//�ر��ļ�
	file.close();

	printf("�����з�����Ŀ�ܹ���: %d\n", total_peaks);

	system("pause");
	//��������
	return 0;
}

bool isPeak(const double grid[][N], int i, int j){
	if(((grid[i-1][j]<grid[i][j]) && (grid[i-1][j-1] < grid[i][j]) && (grid[i-1][j+1] < grid[i][j])) &&//��ǰԪ����һ��
	   ((grid[i+1][j]<grid[i][j]) && (grid[i+1][j-1]<grid[i][j]) && (grid[i+1][j+1]<grid[i][j])) &&//��ǰԪ�ص���һ��
	   ((grid[i][j-1]<grid[i][j]) && (grid[i][j+1]<grid[i][j])))  //��ǰԪ�����ڵ���
	{
			return true;
	}else {
		return false;
	}
}

bool isValley(const double grid[][N], int i, int j){
	if((grid[i-1][j]>grid[i][j]) &&
		(grid[i+1][j]>grid[i][j]) &&
		(grid[i][j-1]>grid[i][j]) &&
		(grid[i][j+1]>grid[i][j])){
			return true;
	}else{ 
		return false;
	}
}

void extremes(const double grid[][N], int row, int column){
	double max = grid[0][0];
	double min = grid[0][0];

	int pos[2][2]={0};//pos[0][0] pos[0][1] ������ߵ������  pos[1][0] pos[1][1] ������͵������ 

	for(int r=0; r<row; r++){
		//printf("\n");
		for(int c=0; c<column; c++){
			//printf(" %lf", grid[r][c]);
			if(max < grid[r][c]){
				max = grid[r][c];
				pos[0][0] = r;
				pos[0][1] = c;
			}

			if(min > grid[r][c]){
				min = grid[r][c];
				pos[1][0] = r;
				pos[1][1] = c;
			}
		}
	}

	printf("���ε����ֵ��%lf  ������: %d ������: %d\n", max, pos[0][0], pos[0][1]);
	printf("���ε���Сֵ��%lf  ������: %d ������: %d\n", min, pos[1][0], pos[1][1]);

}

