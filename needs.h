int nodeID_count = 0;
int timeslot = 0;
int num_overflow = 0;
int num_packets = 0;
int success_pkt;
int delay_acc = 0;

int multipath = 1, adaptive = 0;
double EveryNode[11];


typedef struct Node			/*노드 구조체*/
{
	int nodeID;
	int rank;
	struct Node *preferred_parent;
	double buffer_filled;

}Node;

Node *root;

void initDODAG()						/*초기 DODAG 생성 함수*/
{
	Node *New;
	New = new Node();
	root = New;									// root 노드 생성
	root->nodeID = nodeID_count++;				// root 노드 아이디 설정
	root->rank = 0;								// root 노드 rank = 0 으로
	root->preferred_parent = NULL;				// preferred parent 는 없음
	root->buffer_filled = 0.0;
}


Node *AddChild(Node *parent)					/* parent를 받아 아래 child를 만든 함수 */
{
	Node *New;
	New = new Node();
	New->nodeID = nodeID_count++;
	New->preferred_parent = parent;
	New->rank = parent->rank + 1;
	New->buffer_filled = 0.0;
	return New;
}



void sendmsg(double* from, double* to)
{
	
	if (*from < 1.0) {
		*to = *to+ *from;
		*from = 0.0;
		
	}
	else {
		*from= *from-1.0;
		*to += 1.0;
		
	}

	if (*to >= 10.0) {
		*to = 10.0;
		if(to==EveryNode+4)
			adaptive = 1;
	}

	
}








void print_everynode(void) {
	for (int mp = 0; mp < 11; mp++) {
		printf("%f	", EveryNode[mp]);
	}
	printf("\n");
}