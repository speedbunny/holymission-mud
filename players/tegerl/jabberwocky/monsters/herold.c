/* Tegerl, 24.3.1995 */
/* monsters/herold */


inherit "obj/monster";
reset(arg) 
{
::reset(arg);

if (arg) return;

set_name("herold");
set_alt_name("man");
set_race("human");
set_short("Herold");
set_long("Herold.\n"
       + "He is the king's herold.\n"
       + "He forces you to pay attention to the king's words.\n"
       + "Man is that guy annoying.\n");  
set_level(20);
set_n_wc(15);
set_n_ac(7);
set_gender(1);
set_al(100);
load_chat(20,
({"The herold says: Listen to the words of the king.\n",
  "The herold says: Hear his wisdom and listen to his words.\n",
  "The herold says: The king, the king.\n"
}));
return 1;
}
