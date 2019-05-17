int nodeID_count = 0;
int timeslot = 0;
int num_overflow = 0;
int num_packets = 0;
int success_pkt;
int delay_acc = 0;

int multipath = 1, adaptive = 0;
double EveryNode[11];


typedef struct Node			/*��� ����ü*/
{
	int nodeID;
	int rank;
	struct Node *preferred_parent;
	double buffer_filled;

}Node;

Node *root;

void initDODAG()						/*�ʱ� DODAG ���� �Լ�*/
{
	Node *New;
	New = new Node();
	root = New;									// root ��� ����
	root->nodeID = nodeID_count++;				// root ��� ���̵� ����
	root->rank = 0;								// root ��� rank = 0 ����
	root->preferred_parent = NULL;				// preferred parent �� ����
	root->buffer_filled = 0.0;
}


Node *AddChild(Node *parent)					/* parent�� �޾� �Ʒ� child�� ���� �Լ� */
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