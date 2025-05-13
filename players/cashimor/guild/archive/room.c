#define BARD 6
inherit "guild/room";

string names,instrument,numeral,order;

reset(arg) {
  if(!arg) {
    ::reset(arg);
    set_guild(BARD);
    set_light(1);
    names="##";
    instrument=({"drum#remains#jacket",
                 "flute#stick",
                 "bagpipe#bag#stick",
                 "lute#chest#rope",
                 "bell#bottle#knife",
                 "harp#stick#rope",
                 "mandolin#chest#rope#stick",
                 "piano#chest#rope#stick#sword",
                 "horn#horn",
                 "organ#chest#bag#jacket#stick#axe",
                 "violin#torch#rope#stick",
                 "gong#shield"});
    numeral=({"one","two","three","four","five","six","seven","eight","nine",
              "ten","eleven","twelve","thirteen","fourteen","fifteen",
  "sixteen","seventeen","eighteen","nineteen","twenty",
  "twentyone","twentytwo","twentythree","twentyfour","twentyfive"});
    order=({"first","second","third","fourth","fifth","sixth","seventh",
            "eighth","nineth","tenth","eleventh","twelfth","thirdteenth",
            "fourteenth","fifteenth","sixteenth","eightteenth","nineteenth",
  "twentieth","twentyfirst","twentysecond","twentythird",
  "twentyfourth","twentyfifth"});
  }
}

init() {
  ::init();
  add_action("workroom","workroom");
}

workroom() {
  this_player()->move_player("workroom#players/cashimor/workroom");
  return 1;
}

long() {
  write("This is the brain of Taliesin. Please be careful:\n"
      + "He could hear some of your commands.\n"
      + "There's an exit called 'workroom'.\n");
}

short() {
  return "Guild of Bards";
}

do_join() {
  if(!::do_join()) return;
  if(this_player()->query_alignment()<0) {
    write("You're too nasty to be a real Bard!\n");
    return;
  }
  write("Welcome to the Guild of Bards.\n");
  this_player()->set_guild(gd);
  log_file("cashimor.guild","*** "+this_player()->query_real_name()
         + " joined! ***\n");
  return;
}

add_name(s) {
  if(search_name(s)) return;
  names=names+s+"#";
  return;
}

search_name(s) {
string dummy;

  return sscanf(names,"%s#"+s+"#",dummy);
}

query_instrument(str) {
int getal,ok;
string recept;

  for(getal=0; getal<sizeof(instrument); getal=getal+1) {
    recept=explode(instrument[getal],"#");
    if(recept[0]==str) {
      ok=getal+1;
    }
  }
  return ok;
}

query_needed(i) {
  return explode(instrument[i-1],"#");
}

query_maxsp(lvl) {
  return 40+lvl*10;
}

numberer(str) {
int number;

  if(!str) return 0;
  if(sscanf(str,"%d",number)==1) return number;
  for(number=0; number<sizeof(numeral); number=number+1) {
    if(numeral[number]==str) return number+1;
  }
  for(number=0; number<sizeof(order); number=number+1) {
    if(order[number]==str) return number+1;
  } 
  return 0;
}
