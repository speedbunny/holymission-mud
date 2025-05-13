
/* defines for the fighters */


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
#define _gm  "/guild/master"

