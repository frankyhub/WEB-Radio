
// initializing Senderlist by flash-values - or, if not present, by defaults
void setup_senderList()
{
  sender.begin("senderlist", false);
/*
  strcpy(stationlist[0].name, sender.getString("n1", " Radio-1ARock").c_str());
  strcpy(stationlist[0].url, sender.getString("u1", "http://stream.1a-webradio.de/saw-rock/").c_str());
  
  strcpy(stationlist[1].name, sender.getString("n2", " RT1-Rock").c_str());
  strcpy(stationlist[1].url, sender.getString("u2", "http://mp3.hitradiort1.c.nmdn.net/rt1rockwl/livestream.mp3").c_str());
 */ 
  strcpy(stationlist[0].name, sender.getString("n0", " Radio-BOB!").c_str());
  strcpy(stationlist[0].url, sender.getString("u0", "http://streams.radiobob.de/100/mp3-128/streams.radiobob.de/").c_str());
  
  strcpy(stationlist[1].name, sender.getString("n1", " NRW-Rockradio").c_str());
  strcpy(stationlist[1].url, sender.getString("u1", "http://rnrw.cast.addradio.de/rnrw-0182/deinrock/low/stream.mp3").c_str());
  
  strcpy(stationlist[2].name, sender.getString("n2", " Antenne-Bayern").c_str());
  strcpy(stationlist[2].url, sender.getString("u2", "http://stream.antenne.de/antenne").c_str());
  
  strcpy(stationlist[3].name, sender.getString("n3", " Bayern3").c_str());
  strcpy(stationlist[3].url, sender.getString("u3", "http://dispatcher.rndfnk.com/br/br3/live/mp3/low").c_str());
  
  strcpy(stationlist[4].name, sender.getString("n4", " WDR-COSMO").c_str());
  strcpy(stationlist[4].url, sender.getString("u4", "http://wdr-cosmo-live.icecast.wdr.de/wdr/cosmo/live/mp3/128/stream.mp3").c_str());
  
  strcpy(stationlist[5].name, sender.getString("n5", " N-JOY").c_str());
  strcpy(stationlist[5].url, sender.getString("u5", "http://icecast.ndr.de/ndr/njoy/live/mp3/128/stream.mp3").c_str());
  
  strcpy(stationlist[6].name, sender.getString("n6", " NRW-90er").c_str());
  strcpy(stationlist[6].url, sender.getString("u6", "http://rnrw.cast.addradio.de/rnrw-0182/dein90er/low/stream.mp3").c_str());
  
  strcpy(stationlist[7].name, sender.getString("n7", " Radio-Hagen").c_str());
  strcpy(stationlist[7].url, sender.getString("u7", "http://radiohagen.cast.addradio.de/radiohagen/simulcast/high/stream.mp3").c_str());
  
  strcpy(stationlist[8].name, sender.getString("n8", " Hessen3").c_str());
  strcpy(stationlist[8].url, sender.getString("u8", "http://dispatcher.rndfnk.com/hr/hr3/live/mp3/48/stream.mp3").c_str());
  
  strcpy(stationlist[9].name, sender.getString("n9", " NDR1 Hannover").c_str());
  strcpy(stationlist[9].url, sender.getString("u9", "http://icecast.ndr.de/ndr/ndr1niedersachsen/hannover/mp3/128/stream.mp3").c_str());
  
  strcpy(stationlist[10].name, sender.getString("n10", " NDR2 Niedersachsen").c_str());
  strcpy(stationlist[10].url, sender.getString("u10", "http://icecast.ndr.de/ndr/ndr2/niedersachsen/mp3/128/stream.mp3").c_str());
  
  strcpy(stationlist[11].name, sender.getString("n11", " WDR1").c_str());
  strcpy(stationlist[11].url, sender.getString("u11", "http://wdr-1live-live.icecast.wdr.de/wdr/1live/live/mp3/128/stream.mp3").c_str());
  
  strcpy(stationlist[12].name, sender.getString("n12", " WDR2").c_str());
  strcpy(stationlist[12].url, sender.getString("u12", "http://wdr-wdr2-aachenundregion.icecastssl.wdr.de/wdr/wdr2/aachenundregion/mp3/128/stream.mp3").c_str());
  
  strcpy(stationlist[13].name, sender.getString("n13", " WDR3").c_str());
  strcpy(stationlist[13].url, sender.getString("u13", "http://wdr-wdr3-live.icecastssl.wdr.de/wdr/wdr3/live/mp3/128/stream.mp3").c_str());
  
  strcpy(stationlist[14].name, sender.getString("n14", " MDR").c_str());
  strcpy(stationlist[14].url, sender.getString("u14", "http://mdr-284280-1.cast.mdr.de/mdr/284280/1/mp3/low/stream.mp3").c_str());
  
  strcpy(stationlist[15].name, sender.getString("n15", " RBB").c_str());
  strcpy(stationlist[15].url, sender.getString("u15", "http://dispatcher.rndfnk.com/rbb/rbb888/live/mp3/mid").c_str());
  
  strcpy(stationlist[16].name, sender.getString("n16", " Bayern1").c_str());
  strcpy(stationlist[16].url, sender.getString("u16", "http://dispatcher.rndfnk.com/br/br1/franken/mp3/low").c_str());
  
  strcpy(stationlist[17].name, sender.getString("n17", " Neue Deutsche Welle").c_str());
  strcpy(stationlist[17].url, sender.getString("u17", "http://streams.80s80s.de/ndw/mp3-192/streams.80s80s.de/").c_str());
  
  strcpy(stationlist[18].name, sender.getString("n18", " Deutschlandfunk").c_str());
  strcpy(stationlist[18].url, sender.getString("u18", "http://st01.sslstream.dlf.de/dlf/01/128/mp3/stream.mp3").c_str());
  
  strcpy(stationlist[19].name, sender.getString("n19", " Bayern-Klassik").c_str());
  strcpy(stationlist[19].url, sender.getString("u19", "http://dispatcher.rndfnk.com/br/brklassik/live/mp3/low").c_str());
}
