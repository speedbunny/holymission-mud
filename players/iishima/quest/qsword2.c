inherit "obj/weapon";
void reset(int arg)
{
 ::reset(arg);
 if (arg) return;
 set_name("sword");
 set_alias("#DRAGONSWORD#");
 set_class(5);
 set_weight(1);
 set_value(100);
 set_short("A dragon sword");
 set_long("As you look at this sword, you know there is something special\n"+
          "about it. It has an engraving of a knight slaying a dragon.\n"+
          "Under the picture is an inscription is written in a strange\n"+
          "language. You can only understand two words. LAMTRASHARA and\n"+
          "death.\n");
}

