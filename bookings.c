#include "bookings.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include <string.h>

/* The struct must be defined in bookings.c
 * A booking stores the following information:
 * - name of the guest
 * - The room number
 * - The arrival date (int)
 * - has the guest paid for the room
 */
struct Booking_s {
	char* guest;
	int room;
	int date;
	bool paid;
};

/* Creates a new booking. The name of the guest, the room number
 * and the arrival day are given as parameters.
 *
 * The name of the guest is copied (deep-copy)
 */
Booking* bookingConstruct(const char* guest, int room, int date) {
	assert(guest);
	Booking* b = calloc(1, sizeof(Booking));
	b->guest = calloc(strlen(guest)+1, sizeof(char));
	strcpy(b->guest, guest);
	b->room = room;
	b->date = date;
	b->paid = false;
	return b;
}

Booking* copyOf(const Booking* src) {
	assert(src);
	Booking* copy = bookingConstruct(src->guest, src->room, src->date);
	copy->paid = src->paid;
	return copy;
}

/* Updates the status of the payment (the room is paid).
 * Note that specifying the parameter names is optional in declarations.
 * You can name the parameter in the definition (which should be in bookings.c)
 */
void bookingPay(Booking* booking) {
	assert(booking);
	booking->paid = true;
}

/* Prints the booking information to the file given as parameter. The format is the following:
 *
 * Guest <guest>
 * Room <room>
 * Date <day>
 * Paid / Not paid
 *
 * For example, if the guest name is "Antti", room is 1, date is 2 and the room is not paid,
 * the program prints out the following:
 * Guest Antti
 * Room 1
 * Date 2
 * Not paid
 */
void bookingPrint(FILE* file, const Booking* b) {
	assert(file);
	assert(b);
	fprintf(file, "Guest %s\n", b->guest);
	fprintf(file, "Room %d\n", b->room);
	fprintf(file, "Date %d\n", b->date);
	if (b->paid) {
		fprintf(file, "Paid\n");
	} else {
		fprintf(file, "Not paid\n");
	}
}

/* Frees all memory allocated by the booking */
void bookingDestruct(Booking* booking) {
	assert(booking);
	free(booking->guest);
	free(booking);
}

/* Returns an array that contains all bookings that have been paid for. The last element in both arrays
 * (the returned array and the array given as parameter) is the NULL pointer.
 *
 * The bookings are copied and they appear in the same order as they were in the source array.
 * The returned array is allocated with malloc or calloc and the caller of the function must free it
 * and all its elements when they are no longer needed.
 */
Booking** bookingSelectPaid(Booking** bookings) {
	assert(bookings);
    int paidCount = 0;
	for (int i = 0; bookings[i] != NULL; i++) {
		if (bookings[i]->paid) {
			paidCount++;
		}
	}
	Booking** paidBookings = calloc(paidCount + 1, sizeof(Booking*));
	for (int i = 0, j = 0; bookings[i] != NULL; i++) {
		if (bookings[i]->paid) {
			paidBookings[j] = copyOf(bookings[i]);
			j++;
		}
	}
	return paidBookings;
}
