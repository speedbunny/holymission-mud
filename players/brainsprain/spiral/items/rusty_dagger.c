inherit "obj/weapon";
int randomizer;
void reset(int arg) {
    ::reset();

    set_name("dagger");
    set_alias("rusty dagger");
    set_short("A rusty dagger");
    randomizer=random(5);
    if (randomizer==0 || randomizer ==1){
     set_long(
"A rusty dagger with the tip broken off.  the blade is speckled by rust, "+
"its once fine finish is now dull.  The handle has a long cracking running "+
"the length of it and looks like it is about to fall off.\n");
      }
    if (randomizer==2 || randomizer == 3){
     set_long(
"This dagger is made out of cheap metal and looks very brittle.  A crack "+
"runs the length of this blade.  Here and there speckles of dried blood "+
"are caked to the blade.  The bottom half of the handle is broken off.\n");
      }
    if (randomizer==4){
     set_long(
"It is apparent that this dagger has been ill used.  The blade is made of "+
"tin and has a huge chunk missing from it.  The hilts and handle are covered "+
"in a thick, black slime that almost seems alive.\n");
      }
    set_class(2);
    set_weight(1);
    set_value(25);
}
