int main(string sStr) {
    notify_fail("Finger whom?\n");
    if(!sStr || sStr=="")
        return 0;
    else if(sStr[0..2]=="-p ")
        return "/sys/bin/player/finger"->main(sStr[3..<1]);
    else
        return "/sys/bin/player/finger"->main("-n "+sStr);
}
