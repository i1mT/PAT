#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Station {
	double price;
	double dist;
};

bool cmp (Station a, Station b) {
	return a.dist < b.dist;
}

int main () {

	double capacity, dist, gasrun, sNumber, cost = 0, maxGo, curgas = 0;
	int curs = 0;
	vector<Station> stations;
	Station s;

	scanf("%lf%lf%lf%lf", &capacity, &dist, &gasrun, &sNumber);

	maxGo = gasrun * capacity;

	for (int i = 0; i < sNumber; i++) {
		scanf("%lf%lf", &s.price, &s.dist);

		stations.push_back(s);
	}

	sort(stations.begin(), stations.end(), cmp);

	int nextS, cheapest;
	double needGas;

	if (stations[curs].dist != 0) {
		printf("The maximum travel distance = 0.00\n");
		return 0;
	}

	while (1) {
		nextS = -1;
		cheapest = -1;
		for (int i = curs + 1; i < sNumber; i++) {
			if (stations[i].dist <= stations[curs].dist + maxGo) {
				if (cheapest == -1) cheapest = i;
				else {
					if (stations[i].price < stations[cheapest].price) {
						cheapest = i;
					}
				}

				if (stations[i].price < stations[curs].price) {
						nextS = i;
						break;
				}
			} else {
				break;
			}
		}

		if (nextS != -1) {
			// �ܵ�������˵�վ��
			needGas = (stations[nextS].dist - stations[curs].dist) / gasrun - curgas;
			if (needGas < 0) needGas = 0;
			curgas += needGas;
			cost += needGas * stations[curs].price;

			// ��curs ��nextS
			// printf("not fill %d -> %d  cost: %lf\n", curs, nextS, cost);
			curgas -= (stations[nextS].dist - stations[curs].dist) / gasrun;
			curs = nextS;
		} else if (nextS == -1 && cheapest != -1) {
			// �ڴ˷�Χ�ڵļ���վ���ȵ�ǰ��cheapest�Ǵ˷�Χ������˵�

			// ���ܿ����յ㣬ֱ�ӿ����յ�
			if (stations[curs].dist + maxGo >= dist) {
				// �ܿ����յ�
				needGas = (dist - stations[curs].dist) / gasrun - curgas;
				if (needGas < 0) needGas = 0;
				cost += needGas * stations[curs].price;

				printf("%.2lf\n", cost);
				break;
			}

			// �����ܣ�����ȥ��һ������˵�վ��
			needGas = capacity - curgas;

			cost += needGas * stations[curs].price;

			curgas += needGas;

			// printf("fill %d -> %d  cost:%lf\n", curs, cheapest, cost);
			// ��curs �� cheapest
			curgas -= (stations[cheapest].dist - stations[curs].dist) / gasrun;
			curs = cheapest; 
		} else {
			// ���治�ܵ������վ
			if (stations[curs].dist + maxGo >= dist) {
				// �ܵ����յ�
				needGas = (dist - stations[curs].dist) / gasrun - curgas;
				if (needGas < 0) needGas = 0;
				cost += needGas * stations[curs].price;
				printf("%.2lf\n", cost);
			} else {
				// ���ܵ����յ�
				printf("The maximum travel distance = %.2lf\n", (stations[curs].dist + maxGo));
			}

			break;
		}
 	}

	return 0;
}
