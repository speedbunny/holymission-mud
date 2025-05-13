

/* Tegerl, 6.3.1995 */
/* monsters/gris */


inherit "obj/monster";
reset(arg) 
{
::reset(arg);

if (arg) return;

set_name("griselda");
set_alt_name("girl");
set_race("human");
set_short("Griselda");
set_long("Griselda.\n"
       + "She is a fat girl, a really fat girl.\n"
       + "She completely ignores you.\n"
       + "She takes a potato from her pocket and eats it.\n");  
set_level(20);
set_n_wc(30);
set_n_ac(15);
set_gender(2);
set_al(-120);
load_chat(20,(({
"Griselda takes a potato from her pocket and eats it.\n" })));
return 1;
}
