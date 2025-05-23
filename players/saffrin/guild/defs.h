#define SOUL "/players/saffrin/guild/soul"
#define ATTBY attacked_by
#define CALM stop_fight()
#define CAP capitalize
#define CLONE clone_object
#define CO call_out
#define CRN CAP(TPRN)
#define DEST destruct
#define ENV environment
#define FIND find_object
#define FL find_living
#define FP find_player
#define HERE present
#define HIT hit_player
#define INVALL all_inventory
#define INVF first_inventory
#define INVN next_inventory
#define LC lower_case
#define ME write
#define MOVE move_object
#define MP move_player
#define NF notify_fail
#define PS add_poison
#define QCHA query_cha()
#define QCON query_con()
#define QDEX query_dex()
#define QEL query_earmuff_level()
#define QGH query_ghost()
#define QGOD query_religion()
#define QGP query_money()
#define QGUILD query_guild()
#define QHP query_hp()
#define QINFO query_info()
#define QINT query_int()
#define QINV query_invis()
#define QLGDLVL query_legend_level()
#define QLVL query_level()
#define QMHP query_max_hp()
#define QMSP query_max_sp()
#define QNAME query_name()
#define QNPC query_npc()
#define QOBJ query_objective()
#define QPOSS query_possessive()
#define QPRO query_pronoun()
#define QPSN query_poisoned()
#define QRACE query_race()
#define QRNAM query_real_name()
#define QSEX query_gender()
#define QSH query_short()
#define QSP query_sp()
#define QSTR query_str()
#define QSZ query_size()
#define QVAL query_value()
#define QWC query_wc()
#define QWEP query_weapon()
#define QWGT query_weight()
#define QWIELD query_wielded()
#define QWIS query_wis()
#define QWIZ query_immortal()
#define QXP query_exp
#define RAN random
#define RCO remove_call_out
#define REDHP reduce_hit_points
#define RHP restore_hit_points
#define RSP restore_spell_points
#define RUN run_away()
#define STOP stop_hunter(1)
#define STPWD stop_wielding
#define TELL tell_object
#define TELLRM tell_room
#define TO this_object()
#define TP this_player()
#define TPATT TP->QATT
#define TPCHR TP->QCHR
#define TPD TP->QDEX
#define TPHP TP->QHP
#define TPI TP->QINT
#define TPINV TP->QINV
#define TPL TP->QLVL
#define TPLVL TP->QLVL
#define TPMHP TP->QMHP
#define TPMSP TP->QMSP
#define TPMV TP->MP
#define TPQN TP->QNAME
#define TPOBJ TP->QOBJ
#define TPOSS TP->QPOSS
#define TPRN TP->QRNAM
#define TPRO TP->QPRO
#define TPRSP TP->RSP
#define TPS TP->QSTR
#define TPSEX TP->QSEX
#define TPSKL TP->get_skill
#define TPSP TP->QSP
#define TPW TP->QWIS
#define TPWIZ TP->QWIZ
#define WF write_file
#define WGT add_weight

// GUILD DEFINES
#define GM "guild/master"
#define CD "sys/chatd"
#define ADDSP(x) TP->restore_spell_points(-x)

#define BIN "/players/saffrin/guild/bin/"
#define HELP "/players/saffrin/guild/helpfiles/"
#define SPELL "/players/saffrin/guild/bin/spells/"
#define SHAD "/players/saffrin/guild/bin/shadows/"
#define OBJ "/players/saffrin/guild/bin/obj/"

