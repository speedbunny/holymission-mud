

/* Tegerl, 14.3.1995 */
/* monsters/cam */


inherit "obj/monster";
reset(arg) 
{
::reset(arg);

if (arg) return;

set_name("prophet");
set_alt_name("man");
set_race("human");
set_short("Prophet");
set_long("An old prophet.\n"
       + "He is a very old man and he seems to turn mad.\n"
       + "He is very dirty and his clothes are worn down.\n"
       + "He is a very odd man.\n");  
set_level(80);
set_n_wc(80);
set_n_ac(60);
set_gender(1);
set_al(0);
load_chat(20,(({
"The prophet says: Enter the catapult and fly through the sky and burn as a\n" 
"The prophet says: human star. Use that chance and die a beautiful death.\n" })));
return 1;
}
