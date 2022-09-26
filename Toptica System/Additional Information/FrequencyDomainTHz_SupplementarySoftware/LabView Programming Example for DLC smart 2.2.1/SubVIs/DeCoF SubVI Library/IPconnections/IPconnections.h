// IPconnections.h

#pragma once

/**
Query the number of available IPv4 network interfaces of the
machine running this library.

@return Number of available IPv4 network interfaces
*/
extern "C" __declspec(dllexport)
int nIPconnections();

/**
Query the IP and broadcast addresses (IPv4) of the machine
running this library.

@param addresses array (size n) where the IP addresses of the
network interfaces will be stored.
@param broadcast array (size n) where the broadcast addresses
of the network interfaces will be stored.
@param n size of arrays addresses and broadcast. Note that this
function will return an error if n does not match the number of
network interfaces found by the function (see nIPconnections())
@return error indicator: 0 if no error occured; -1 else
*/
extern "C" __declspec(dllexport)
int IPconnections
(u_long *addresses,
 u_long *broadcast,
 int n);