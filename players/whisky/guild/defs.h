
/* defines for the monksoul */


closure call;

void reset(int flag)
{
    if (flag == 0)
       call = #'call_other;
}

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
#define _e   environment
#define _obj "/players/whisky/guild/obj/"
#define _shad "/players/whisky/guild/shadows/"
#define _gm  "/guild/master"
#define _lg  (apply(call,_tp,"query_property","monk_legend") + 1)
#define _dam(x)  x  +  (x / 20 * _lg)
#define _cost(x) x  -  (x / 20 * _lg)


// the skilladvantage _tpi(+) _tpd(+) s(-) d(-) _tpi!=_tpd(-)
#define _adv(s,d) !random( ( (_tpi + _tpd) * 10 * s * d )/(_tpi * _tpd) )

mixed _chk_ghost()
{
      if (apply(call,_tp,"query_ghost"))
      {
         notify_fail("");
         return 0;
      }
}
