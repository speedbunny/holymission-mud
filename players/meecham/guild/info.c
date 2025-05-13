mapping SPELLS;

void reset(status arg) {
  if (arg) return;
  SPELLS = 
    ([ "barkskin"       :  50;  4, "call lightning"      :  45; 12, 
       "cause critical" :  70; 17, "cause light"         :  30;  2, 
       "cause serious"  :  50;  9, "create"              : 100;  1, 
       "cure critical"  :  70; 16, "cure light"          :  30;  1,
       "cure serious"   :  50;  8, "detect invisibility" :  30;  3,
       "entangle"       :  60; 15, "faerie fire"         :  30;  6,
       "fireshield"     : 200; 25, "firestorm"           : 120; 28,
       "flame blade"    :  50; 10, "grow tree"           : 100;  7, 
       "harm"           : 100; 24, "heal major"          : 200; 29,
       "heal minor"     : 100; 23, "heat armour"         : 150; 27,
       "light"          :  20;  3, "remove poison"       :  70;  9,
       "slay living"    : 300; 34, "tree travel"         :  20;  1,
       "harness wind"   :  50;  1, "earthquake"          :  80; 13,
       "true sight"     :  80; 20
    ]);
}
 
int get_cost(string skill) {
  return (SPELLS[skill,0]);
}

int get_level(string skill) {
  return (SPELLS[skill,1]);
}
