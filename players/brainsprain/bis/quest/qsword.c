inherit "obj/weapon";

int hit(string ob){
  if(ob = "darkstaff") {
 return  write("Your sword slides into Darkstaffs chest, instantly killing him!\n"), 10000;
  }
  return 1;
}

void reset(int arg){
    ::reset();

    set_id("Longsword");
    set_alias("#questsword#");
    set_alt_name("sword");
    set_short("A magnificient longsword");
    set_long(
"An inner light glows from the interior of the blade of this sword.  Its "+
"finely crafted hilts are crusted with diamonds and rubies.  The blade "+
"itself is made of incredibly dense steel.  The handle has several runes "+
"emblazoned on it.  The balance of this blade is perfect.\n");
    set_class(1);
    set_weight(2);
    set_value(0);
}
void init(){
  ::init();
  }
