# OpenLTE-CSI

## Introduction

This is a modified version of OpenLTE able to extract Channel State Information (CSI) from LTE signals developed by Giovanni Pecoraro (giovanni1.pecoraro@protonmail.com).

## Publications

This is the list of the published papers by using this tool:

- G. Pecoraro, E. Cianca, M. De Sanctis, S. Di Domenico, [LTE Signal Fingerprinting Device-Free Passive Localization in Changing Environments](https://journals.riverpublishers.com/index.php/JMM/article/view/947), Journal of Multimedia, 2020
- G. Pecoraro, E. Cianca, S. Di Domenico, M. De Sanctis, [LTE Signal Fingerprinting Device-Free Passive Localization Robust to Environment Changes](https://ieeexplore.ieee.org/abstract/document/8686686), Global Wireless Summit (GWS), 2018, Best Paper Award 
- G. Pecoraro, S. Di Domenico, E. Cianca, M. De Sanctis, [CSI-based fingerprinting for indoor localization using LTE Signals](https://link.springer.com/article/10.1186/s13634-018-0563-7), EURASIP Journal on Advances in Signal Processing, 2018
- G. Pecoraro, S. Di Domenico, E. Cianca, M. De Sanctis, [LTE signal fingerprinting localization based on CSI](https://ieeexplore.ieee.org/abstract/document/8115803), IEEE 13th International Conference on Wireless and Mobile Computing, Networking and Communications (WiMob), 2017

*****************************************************************************************************

This directory contains the openLTE source code.  For support, please subscribe to openlte-discuss@lists.sourceforge.net.  Details can be found at sourceforge.net/projects/openlte/.

The directory structure for the project is:
```
octave                  Octave test code
matlab                  MATLAB test code for multiple cell analysis
cmn_hdr                 Common header files
liblte                  C++ library of commonly used LTE functions
libgraph                C++ library of GUI functions
cmake                   Files needed for cmake
LTE_data_acquire        Scripts to acquire LTE data
LTE_fdd_dl_file_gen     A gnu-radio LTE FDD DL file generator application
LTE_fdd_dl_file_scan    A gnu-radio LTE FDD DL file scanner application
LTE_fdd_dl_file_track   A gnu-radio LTE FDD DL file tracker application
LTE_fdd_dl_scan         A gnu-radio LTE FDD DL scanner application that
                        currently supports rtl-sdr, hackrf, USRP B2X0,
                        and bladeRF hardware
LTE_fdd_dl_track        A gnu-radio LTE FDD DL tracker application that
                        currently supports rtl-sdr, hackrf, USRP B2X0,
                        and bladeRF hardware
LTE_file_recorder       A gnu-radio LTE file recording application that
                        currently supports rtl-sdr, hackrf, USRP B2X0,
                        and bladeRF hardware
LTE_fdd_enodeb          An LTE FDD eNodeB application that currently
                        supports URSP B2X0 hardware
```

openLTE is dependant on the following:

1) GNU Radio
2) GrOsmoSDR
3) rtl-sdr
4) UHD
5) HackRF
6) bladeRF
7) polarssl
8) iptables

To build the C++ and python code use the following:

```bash
$ mkdir build
$ cd build
$ cmake ../
$ make
```

To install the C++ and python code use the following:

```bash
$ mkdir build
$ cd build
$ cmake ../
$ make
$ sudo make install
```

All testing was performed against the following configuration:

- Intel Core i5-2557M
- Ubuntu 12.04
- GNU Radio 3.7.2
- GrOsmoSDR 0.1.1
- rtl-sdr 0.5
- UHD 3.6.0-1
- HackRF 0.2
- bladeRF 0.9.0

###  FILE SCANNER

To use the installed C++ and python code for the file scanner, set the PYTHONPATH env variable to `<python_install_dir>/dist-packages/gnuradio/` for instance `/usr/local/lib/python2.7/dist-packages/gnuradio/` and make sure that `/usr/local/lib` is added to `/etc/ld.so.conf` and that `LD_LIBRARY_PATH` is set to `/usr/local/lib` (`export LD_LIBRARY_PATH=/usr/local/lib`).  Then run `LTE_fdd_dl_file_scan.py` and specify a recorded LTE file as the input. For example:

```bash
$ LTE_fdd_dl_file_scan.py lte_file.bin
```

To see a list of options, use the -h option:

```bash
$ LTE_fdd_dl_file_scan.py -h
```

To change the input file data type (int8 or gr_complex), use the -d/--data-type option:

```bash
$ LTE_fdd_dl_file_scan.py -d int8 lte_file.bin
```

For int8 data type, the recorded LTE file must be interleaved signed 8-bit I and Q samples.  For the gr_complex data type, the recorded LTE file must be sequential gr_complex I/Q samples.  Files recorded with LTE_file_recorder or generated with LTE_fdd_dl_file_gen can be scanned with this application.

###  FILE GENERATOR
To use the installed C++ and python code for the file generator, set the PYTHONPATH env variable to `<python_install_dir>/dist-packages/gnuradio/` for instance `/usr/local/lib/python2.7/dist-packages/gnuradio/` and that `LD_LIBRARY_PATH` is set to `/usr/local/lib` (`export LD_LIBRARY_PATH=/usr/local/lib`). Then run `LTE_fdd_dl_file_gen.py` and specify an output file for the LTE fdd downlink signal. For example:

```bash
$ LTE_fdd_dl_file_gen.py lte_file.bin
```

To see a list of options, use the -h option:

```bash
$ LTE_fdd_dl_file_gen.py -h
```

To change the output file data type (int8 or gr_complex), use the -d/--data-type option:

```bash
$ LTE_fdd_dl_file_gen.py -d gr_complex lte_file.bin
```

For int8 data type, the generated LTE file contains interleaved signed 8-bit I and Q samples. For the gr_complex data type, the generated LTE file contains sequential gr_complex I/Q samples. Files generated with this application can be scanned with LTE_fdd_dl_file_scan.

###  SCANNER
To use the installed C++ live scanner, make sure `LD_LIBRARY_PATH` is set to `/usr/local/lib` (`export LD_LIBRARY_PATH=/usr/local/lib`), plug in rtl-sdr, hackrf, USRP B2X0, or bladeRF hardware, run LTE_fdd_dl_scan, and connect (via telnet, nc, etc) to the control port at port number 20000.  Scan parameters can be changed and scan results can be observed on the control port.  For a list of parameters simply type help on the control port.

###  FILE RECORDER
To use the installed C++ file recorder, make sure `LD_LIBRARY_PATH` is set to /usr/local/lib (export LD_LIBRARY_PATH=/usr/local/lib), plug in rtl-sdr, hackrf, USRP B2X0, or bladeRF hardware, run LTE_file_recorder, and connect (via telnet, nc, etc) to the control port at port number 25000.  Recording parameters can be changed on the control port.  For a list of parameters simply type help on the control port.  Files recorded using hackRF, USRP B2X0, or bladeRF hardware are recorded using a sample rate of 15.36MHz. Files recorded with all other hardware are recorded using a sample rate of 1.92MHz.  All files recorded with this application can be scanned with LTE_fdd_dl_file_scan.

###  ENODEB
To use the installed C++ eNodeB, make sure `LD_LIBRARY_PATH` is set to `/usr/local/lib` (`export LD_LIBRARY_PATH=/usr/local/lib`), plug in USRP B2X0 hardware, run LTE_fdd_enodeb, and connect (via telnet, nc, etc) to the control port at port number 30000.  eNodeB parameters can be changed on the control port.  For a list of parameters simply type help on the control port.  A MAC and above level PCAP trace is output to /tmp/LTE_fdd_enodeb.pcap.  Data packets are routed through a tun device named tun_openlte.  Wireshark can be used to observe IP packets on tun_openlte to inspect the IP traffic to/from UEs. In order to configure properly, set the ip_addr_start parameter to the begining of a non-conflicting private address range (i.e. 10.0.0.1) and set the dns_addr parameter to the primary DNS address listed by your modem.  All UEs will be assigned IP addresses in the range of ip_addr_start to ip_addr_start+254 and all traffic will be tunneled through the tun device to the internet using NAT/iptables. NOTES: This application has been tested exclusively at 5MHz bandwidth.  Higher bandwidths are supported and performance may vary based on processing hardware. WARNINGS: By using this application you risk disruption of service in a public network, even if you are not directly interfering with the radio transmissions.  This is a criminal act in most countries, and a much more serious offense than a simple violation of radio spectrum regulaions.  It is highly recommended to use this application only with antennas and test UEs inside an RF Shielded Enclosure (Faraday Cage).

###  OCTAVE
To use the octave code, run the top level octave .m files: `lte_fdd_dl_transmit.m` and `lte_fdd_dl_receive.m`.  If multiple transmit antennas are used, the outputs need to be combined before input to the receiver.
