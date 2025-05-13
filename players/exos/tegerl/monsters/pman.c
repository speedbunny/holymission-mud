

/* Tegerl, 10.3.1995 */
/* monsters/pman */


inherit "obj/monster";
reset(arg) 
{
::reset(arg);

if (arg) return;

set_name("poor man");
set_alt_name("man");
set_race("human");
set_short("Poor man");
set_long("A poor man.\n"
       + "He really owns nothing.\n"
       + "He wants to start a new life in town.\n");  
/* Exos 4-26-97
set_level(10);
Level Change */
set_level(5);
set_gender(1);
set_al(40);
}
