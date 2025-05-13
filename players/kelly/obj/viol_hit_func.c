/* Used by Prince Violens's Holy Avenger */
 
/* If you change this, change crossing.c too: */
#define WEAPON_CLASS 20
 
weapon_hit(victim) {
 if (call_other(victim, "query_name") == "Obliterator") {
  if (!random(3)) {
   write("The holy avenger screams loudly while hitting Obliterator!\n");
   say("The holy avenger screams loudly while hitting Obliterator!\n");
   return 35;
  }
  return 10;
 }
 else {
  write("The holy avenger is made for only one mission.\n");
  return - WEAPON_CLASS + 3;
 }
} /* weapon_hit */
