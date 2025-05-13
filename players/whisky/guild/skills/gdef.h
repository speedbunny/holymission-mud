/* the list of defines for the monk_skills */

#define _tp   this_player()
#define _tpn  apply(call,_tp,"query_name")
#define _tpr  apply(call,_tp,"query_real_name")
#define _tpp  apply(call,_tp,"query_possessive")
#define _tpl  apply(call,_tp,"query_level")
#define _tpo  apply(call,_tp,"query_pronoun")
#define _tps  apply(call,_tp,"query_sp")
#define _tph  apply(call,_tp,"query_hp")
#define _tpw  apply(call,_tp,"query_wis")
#define _tpd  apply(call,_tp,"query_dex")
#define _tpst apply(call,_tp,"query_str")
#define _tpi  apply(call,_tp,"query_int")
#define _tpc  apply(call,_tp,"query_con")
#define _tpe  apply(call,_tp,"enhanced_dam")
#define _e   environment
#define _obj "/players/whisky/guild/obj/"
#define _shad "/players/whisky/guild/shadows/"
#define _gm  "/guild/master"
#define _lg     apply(call,_tp,"query_legend_level")
//#define _lg  (apply(call,_tp,"query_property","monk_legend")+1)
#define _dam(x)  (x + _tpe + ( (_lg * x) / 5) )
#define _cost(x) (x  -  ( (_lg * x) / 40 ) )
#define _shad "/players/whisky/guild/shadows/"

#define _adv(s,d) !random(s * d)
#define _suc(s) (random(90000/(100+8*s)) <= 100)
