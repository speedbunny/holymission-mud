inherit "obj/weapon";
void reset(int arg){
    ::reset();

    set_name("longsword");
    set_alias("sword");
    set_alt_name("weapon");
    set_short("longsword");
    set_long(
"This is a plain steel sword of a castle guard.  It bears the ensignia "+
"of the House Bismarck.  Along the length of the blade, someone has "+
"carved a dragon.  The sword shines and has obviously been polished "+
"recently.\n");
    set_class(8);
    set_weight(2);
    set_value(100);
}
