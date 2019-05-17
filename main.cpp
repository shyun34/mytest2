#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>
#include <math.h>
#include <deque>
#include <iostream>
#include "needs.h"


int main(void) {


	for (int slotframes = 0; slotframes < 100; slotframes++) {

		for (int mp = 6; mp < 11; mp++) {
			EveryNode[mp] += 0.5;
		}

		for (int mp = 3; mp < 6; mp++) {
			EveryNode[mp] += 0.2;
		}

		for (int mp = 1; mp < 3; mp++) {
			EveryNode[mp] += 1.0 / 7.0;
		}



		sendmsg(EveryNode + 1, EveryNode + 0);
		sendmsg(EveryNode + 5, EveryNode + 2);
		sendmsg(EveryNode + 7, EveryNode + 4);

		if (multipath == 1 || adaptive == 1) {
			sendmsg(EveryNode + 8, EveryNode + 3);
		}

		timeslot++;


		//=====Slot 0=======

		sendmsg(EveryNode + 2, EveryNode + 0);
		sendmsg(EveryNode + 8, EveryNode + 4);

		if (multipath == 1) {
			sendmsg(EveryNode + 7, EveryNode + 5);
			sendmsg(EveryNode + 9, EveryNode + 3);
		}
		//Sleep(20);
		timeslot++;


		//=====Slot 1=======

		sendmsg(EveryNode + 9, EveryNode + 4);

		if (multipath == 1) {
			sendmsg(EveryNode + 8, EveryNode + 5);
			sendmsg(EveryNode + 10, EveryNode + 3);
		}
		//Sleep(20);
		timeslot++;


		//=====Slot 2=======

		sendmsg(EveryNode + 3, EveryNode + 1);
		sendmsg(EveryNode + 10, EveryNode + 4);

		if (multipath == 1 || adaptive == 1) {
			sendmsg(EveryNode + 9, EveryNode + 5);
		}
		//Sleep(20);
		timeslot++;


		//=====Slot 3=======

		sendmsg(EveryNode + 4, EveryNode + 1);
		sendmsg(EveryNode + 6, EveryNode + 3);

		if (multipath == 1 || adaptive == 1) {
			sendmsg(EveryNode + 10, EveryNode + 5);
		}
		//Sleep(20);
		timeslot++;


		//=====Slot 4=======

		if (multipath == 1) {
			sendmsg(EveryNode + 4, EveryNode + 2);
			sendmsg(EveryNode + 5, EveryNode + 1);
			sendmsg(EveryNode + 7, EveryNode + 3);
			//Sleep(20);
			timeslot++;


			//======Slot 5========

			sendmsg(EveryNode + 3, EveryNode + 2);
			sendmsg(EveryNode + 6, EveryNode + 4);
			//Sleep(20);
			timeslot++;

			//=======Slot 6========
		}
		else if (adaptive == 1) {
			sendmsg(EveryNode + 4, EveryNode + 2);
			sendmsg(EveryNode + 7, EveryNode + 3);
			//Sleep(20);
			timeslot++;
		}


		EveryNode[0] = 0.0;

		if (EveryNode[4] <= 5.0)
			adaptive = 0;

		print_everynode();
	}
	return 0;
}