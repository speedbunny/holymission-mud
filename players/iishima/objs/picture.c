inherit "obj/treasure";

drop() { write("You drop the picture and it vanishes.\n"); destruct(this_object()); return 1; }
reset(arg) {
  if (!arg) {
  set_id("picture");
  short_desc=("Picture of Iishima");
long_desc=("!!!!!!!!!!!!!!!X!!!!!!!!XX!!!!!!!!!!!!!!!!!!!!!!~~\n"+
"!!!!!!!!!!!!!XMM!!!!!!XMMM!!!!!!!!!!!!!!!!!!!!!:<:\n"+
"!!!!!!!!!!!!MMM!!!!XXMMMM!!!!!!!!!!!!!!!!!!!!!!!!!\n"+
"!!!!!!!!!!XMMMMXXHMMMMMMM!!XX!!!!!!!!!!!!!!!!!!!!!\n"+
"!!!XM!HMXHMMMMMMMMMMMMMMMHMMMHM!!XXX!!!!!!!!!!!!!!\n"+
"HXXX!X!XMMMMMMMMMMMMMMMMM?MMMMMMXMMM!!!!!!!!!!!!!!\n"+
"M?!MM!XMMMMMMMMMMMM\"\"~``     `\"*MMMM!!!!!!!!!!!!!!\n"+
"MM!!XMMMMMMMMMMMM\"              `\"MXX!!!!!!!!!!!!!\n"+
"M!!XMMMMMMMMMMM*`        `        `MMX!!!!!!!!!!!!\n"+
"!XMMMMMMMMMMMMf                    'MMX!!!!!!!!!!!\n"+
"HMMMMMMMMMMMMM                      ?M!X!!!!!!!!!!\n"+
"MMMMMMMMMMMMM>        .::.xHHx. .    !!!X!!!!!!!!!\n"+
"MMMMMMMMMMMMM       :!!MMMM$$$$MMX!   !XX!!!!!!!!!\n"+
"MMMMMMMMMMMMX     ~:!!HMMMMM$$$MMMX!  !MMX!!!!!!!!\n"+
"MMMMMMMMMMMMf    ~~~!!MMM@$$$$$$8MM!  XMMX!!!!!!!!\n"+
"MMMMMMMMMMMM>     ~~ ::..!?R$$R??\"`~ :MMMMX!!!!!!!\n"+
"MMMMMMMMMMMMk:   <~:!~~~X!!M$R!!!??! XMMMM!!!!!!!!\n"+
"MMMMMMMMMM8$R<!: <~!XX!!XX!!MRX!!:!XXMMMMM!!!!!!!!\n"+
"$@MMMMMMM$$RR!!/  <!MMMMMM!!MMMMHHMXMMMMMM!!!!!!!!\n"+
"$MMMMM8$$$5MX~!!~'~!MM$$R!!XM$MMR$MXMMMMMM!!!!!!!!\n"+
"BRMM8$$$$$$M!>  '~<!!MMMMHXXXSXMMMMXMMMMMMX!!!!!!!\n"+
"8M8$$$$$$BMMX    ~!!!M??!!MMMMM?MM!XMMMMMMMXX!!!!!\n"+
"$$$$$$$$M$$8M    '~!!MM%!!%@t@!HMMXMMMMMMMMMMX!!!!\n"+
"$$$$$$$$B$BB$W:  '~~!!MM!XXSMMHMMXMMMMMMMMMMM!!!!!\n"+
"$$$$$$$$$$$$$$$WW<!~~!!!MMMM8$MMXMMMMMMMMMMMM!!!!!\n"+
"$$$$$$$$$$$$$$$$$<!!:~~~!MM$$$MXMMMMMMMMMMMMMM!!!!\n"+
"$$$$$$$$$$$$$**# !!X!<~~~~?#M?XXMMMMMMMMMMMMMM!!!!\n"+
"$$$$$$$$$$$R\" '!!!MMMXX!!!!M!X!!MMMMMMMMMMMMM?!!!!\n"+
"$$$$$$$$$*\"     ~XMMM$MMMMMMHMHX ^\"*MMMMMMMMMMX!!!\n"+
"$$$$$$$#`        '\"@B$$$MMMMMMM\"     `*MMMMMMMXHX!\n"+
"$$$$$#`             ^#*$$8B$$*`        `\"*MMMMMM?!\n"+
"$$R\"                    `````              `*MMM!!\n"+
"*\"                                           `M!!!\n"+
"                                               !!!\n"+
"                                               `!!\n"+
"                                                `!\n"+
"                                                 !\n"+
"~                                                '\n"+
"                                                  \n"+
"                                      ::          \n"+
">                                    4!`~         \n"+
"                                      !H          \n"+
"`:                                    .~          \n");
  set_value(0);
  set_weight(0);
  return 1;
 }
}
