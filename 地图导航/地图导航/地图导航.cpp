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

	cout <<"请输入文件名.\n";
	cin  >> filename;

	file.open(filename.c_str());
	if(file.fail()){
		cerr<<"打开输入文件出错.\n";
		exit(1);
	}

	file>>nrows>>ncols;

	if(nrows > N || ncols > N){
		cerr<<"网格太大，调整程序.\n";
		exit(1);
	}

	//从数据文件读数据到数组
	for(int i=0; i<nrows; ++i){
		for(int j=0; j<ncols; ++j){
			file>>map[i][j];
		}
	}

	int total_peaks = 0;

	//判断并打印峰值位置
	for(int i=1;i<nrows-1; ++i){
		for(int j=1;j<ncols-1; ++j){
			if(isPeak(map, i, j)){
				cout<<"峰值出现在行: "<<i<<" 列:"<<j<<endl;
				total_peaks++;
			}else if(isValley(map, i, j)){
				cout<<"谷点出现在行: "<<i<<" 列:"<<j<<endl;
			}
		}
	}

	//打印海拔的最大值和最小值，以及它们所在的位置
	extremes(map, nrows, ncols);

	//关闭文件
	file.close();

	printf("网格中峰点的数目总共是: %d\n", total_peaks);

	system("pause");
	//结束程序
	return 0;
}

bool isPeak(const double grid[][N], int i, int j){
	if(((grid[i-1][j]<grid[i][j]) && (grid[i-1][j-1] < grid[i][j]) && (grid[i-1][j+1] < grid[i][j])) &&//当前元素上一行
	   ((grid[i+1][j]<grid[i][j]) && (grid[i+1][j-1]<grid[i][j]) && (grid[i+1][j+1]<grid[i][j])) &&//当前元素的下一行
	   ((grid[i][j-1]<grid[i][j]) && (grid[i][j+1]<grid[i][j])))  //当前元素所在的行
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

	int pos[2][2]={0};//pos[0][0] pos[0][1] 保存最高点的坐标  pos[1][0] pos[1][1] 保存最低点的坐标 

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

	printf("海拔的最大值：%lf  所在行: %d 所在列: %d\n", max, pos[0][0], pos[0][1]);
	printf("海拔的最小值：%lf  所在行: %d 所在列: %d\n", min, pos[1][0], pos[1][1]);

}

