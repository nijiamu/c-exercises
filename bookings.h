#ifndef BOOKINGS_H
#define BOOKINGS_H

#include <stdio.h>

/* The struct must be defined in bookings.c
 * A booking stores the following information:
 * - name of the guest
 * - The room number
 * - The arrival date (int)
 * - has the guest paid for the room
 */
typedef struct Booking_s Booking;

/* Creates a new booking. The name of the guest, the room number
 * and the arrival day are given as parameters.
 *
 * The name of the guest is copied (deep-copy)
 */
Booking *bookingConstruct(const char *guest, int room, int date);

/* Updates the status of the payment (the room is paid).
 * Note that specifying the parameter names is optional in declarations.
 * You can name the parameter in the definition (which should be in bookings.c)
 */
void bookingPay(Booking *);

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
void bookingPrint(FILE *, Booking const *);


/* Frees all memory allocated by the booking */
void bookingDestruct(Booking *);

/* Returns an array that contains all bookings that have been paid for. The last element in both arrays
 * (the returned array and the array given as parameter) is the NULL pointer.
 *
 * The bookings are copied and they appear in the same order as they were in the source array.
 * The returned array is allocated with malloc or calloc and the caller of the function must free it
 * and all its elements when they are no longer needed.
 */

Booking **bookingSelectPaid(Booking **);



#endif
