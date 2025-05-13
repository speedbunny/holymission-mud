inherit "/obj/thing";

#include "/players/sauron/include/include.h"

int is_open;
object demon;

void set_card_open(int i) {
  is_open=i;
}

int query_card_open() {
  return is_open;
}

int cd14() {
  TELLR(ENV(TP),"The Tiny Demon frowns, then folds itself into \
nothingness.\n");
  if(demon)
    DE(demon);
}

int cd13() {
  TELLR(ENV(TP),"Tiny Demon waves a minute pointed hand.\n");
  call_out("cd14",2);
}

int cd12() {
  WRITE("Tiny Demon hugs you, in a way only a tiny paper Tiny Demon could.\n");
  say(lw("Tiny Demon hugs "+CNAME(TP)+", in a way only a tiny paper Tiny \
Demon could.\n"));
  call_out("cd13",2);
}

int cd11() {
  TELLR(ENV(TP),"Tiny Demon sings: The end!\n");
  call_out("cd12",2);
}

int cd10() {
  TELLR(ENV(TP),"Tiny Demon sings: and a Happy New Year.\n");
  call_out("cd11",2);
}

int cd9() {
  TELLR(ENV(TP),"Tiny Demon sings: We wish you a Merry Christmas,\n");
  call_out("cd10",2);
}

int cd8() {
  TELLR(ENV(TP),"Tiny Demon sings: To you and your kin,\n");
  call_out("cd9",2);
}

int cd7() {
  TELLR(ENV(TP),"Tiny Demon sings: Glad tidings we bring,\n");
  call_out("cd8",2);
}

int cd6() {
  TELLR(ENV(TP),"Tiny Demon pauses for breath...\n");
  call_out("cd7",2);
}

int cd5() {
  TELLR(ENV(TP),"Tiny Demon sings: and a Happy New Year.\n");
  call_out("cd6",2);
}

int cd4() {
  TELLR(ENV(TP),"Tiny Demon sings: We wish you a Merry Christmas,\n");
  call_out("cd5",2);
}

int cd3() {
  TELLR(ENV(TP),"Tiny Demon sings: We wish you a Merry Christmas,\n");
  call_out("cd4",2);
}

int cd2() {
  TELLR(ENV(TP),"Tiny Demon sings: We wish you a Merry Christmas,\n");
  call_out("cd3",2);
}

int cd1() {
  TELLR(ENV(TP),"Tiny Demon takes a deep breath...\n");
  call_out("cd2",2);
}

void long() {
  if(!query_card_open())
    WRITE("A Christmas card from The Dark Lord. Maybe you should open it.\n");
  else
    WRITE(
 "_________________________________________________________________________\n"
+"\n"
+"          *                 *       |\n"
+"             *    .                 |     MERRY CHRISTMAS\n"
+"                 / \\   *            |\n"
+"                /O  \\               |           AND A HAPPY NEW YEAR\n"
+"         *     /_   _\\              |\n"
+"                /  O\\    *          |\n"
+"           *   /_   _\\       *      |\n"
+"                 |_|                |         FROM THE DARK LORD\n"
+"     * * * * * * * * * * * * * *    |\n"
+"\n"
+"_________________________________________________________________________\n"
);
}

int card_open(string str) {
  if(!str || str!="card") {
    NF("Open what?\n");
    return 0;
  }
  else if(query_card_open()) {
    WRITE("The card is already open.\n");
    return 1;
  }
  WRITE("A cute little baby demon explodes from your card as you open it!\n");
  say(lw("A cute little baby demon explodes from "+CNAME(TP)+"'s card as "
     +HE(TP)+" opens it!\n"));
  demon=CO("/obj/monster");
  demon->set_name("demon");
  demon->set_short("A Tiny demon");
  demon->set_long("A cute little baby demon.\n"
                 +"It's singing it's little heart out.\n");
  demon->set_gender(0);
  demon->set_level(1);
  demon->set_wc(0);
  demon->set_ac(1000000);
  demon->set_hp(1000000);
  MOVE(demon,ENV(TP));
  call_out("cd1",2);
  set_card_open(1);
  return 1;
}

int drop2() {
  TELLR(ENV(TO),"The card vanishes.\n");
  DE(TO);
  return 1;
}

int drop() {
  call_out("drop2",2);
  return 0;
}

int kill_demon(string str) {
  if(!str || str!="demon") {
    NF("Kill what?\n");
    return 0;
  }
  else {
    WRITE("You want to kill the cute little baby demon, your Christmas \
present from The Dark Lord?\n");
    return 1;
  }
}

void reset(int arg) {
  ::reset(arg);
  if(!arg) {
    set_name("card");
    set_alias("xmas_card");
    set_alt_name("christmas_card");
    set_short("A Christmas card");
    set_weight(1);
    set_value(0);
    set_card_open(0);
  }
}

void init() {
  ::init();
  add_action("card_open","open");
  add_action("kill_demon","kill");
}
