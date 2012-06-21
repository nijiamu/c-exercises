#include "bookings.h"
#include <stdio.h>
#include <stdlib.h>

int main() {

  Booking *antti = bookingConstruct("Antti", 1, 10);
  bookingPrint(stdout, antti);
  bookingPay(antti);

  Booking *raimo = bookingConstruct("Raimo", 2, 20);
  Booking *petteri = bookingConstruct("Petteri", 3, 30);

  bookingPay(petteri);
  // Raimo didn't pay for his room


  // An array of Booking pointers. The last element is NULL.
  Booking *bookings[] = {antti, raimo, petteri, NULL};
  // The function returns an array {antti, petteri, NULL}
  Booking **paidBookings = bookingSelectPaid(bookings);
  printf("----\n");
  for (int i = 0; paidBookings[i] != NULL; ++i)
    bookingPrint(stdout, paidBookings[i]); // Prints the paid bookings to standard output
  for (int i = 0; paidBookings[i] != NULL; ++i)
    bookingDestruct(paidBookings[i]);
  free(paidBookings);

  bookingDestruct(raimo);
  bookingDestruct(antti);
  bookingDestruct(petteri);
  
}
