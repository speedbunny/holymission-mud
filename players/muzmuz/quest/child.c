

inherit "obj/monster";

string *chat;

void reset (int arg)
{
   ::reset(arg);

    if (arg == 0) 
    {
      chat = ({ 
      "The girl sniffs.\n",
      "The girl sobs.\n",
      "The girl says: I lost my guineapig.\n",
      "The girl says: I don't know what to do.\n",
      "The girl says: Please bring back my guineapig !\n"
      });
      set_name("girl");
      set_alt_name("questgirl");
      set_short(query_name()); 
      set_level(2);
      set_long(
      "The girl is alone at home. For her parents are not here\n"+
      "she is scared a bit.\n");
      load_chat(40,chat);
    }
}


void catch_tell(string arg) 
{
   if (present("guineapig",environment()))
   {
    chat = ({
    "The girl cuddles the guineapig.\n",
    "The girl jumps around happily.\n",
    "The girl says: My guineapig is back !\n",
    });
    this_object()->load_chat(40,chat);
   }
}
