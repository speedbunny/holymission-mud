/* the gambling table */
inherit "obj/container";

void reset(int arg) {
   ::reset(arg);

   if(!arg) {
      set_name("tree stump");
      set_alias("stump");
      set_short("A tree stump");
      set_long("A big tree stump serves as a table to the vikings. \n"
             + "Something is written in it by means of a hot item. \n");
      set_closed(0);
      set_opened();
      set_max_weight(10);
      set_can_get(0);
      set_read("T R I P L E   A C E \n"
        + "Once the bet is placed, 'gamble' with the viking. You may roll the dice thrice. \n"
        + "Get as many of the same numbers as you can. The one with the most wins. \n"
        + "High sets win over low sets. At a tie of pairs the value of the last die \n"
        + "decides. Otherwise chance makes the winner. Triple one always wins! \n"
        + "On 2nd and 3rd roll, roll the die numbers you want to roll over. \n"
        + "E.g. 'roll 1, 3' rolls the first and thrid die again, holding the second. \n"
        + "'Roll 0' for no changes. \n");
      }
   }
