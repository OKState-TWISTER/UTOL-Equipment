Labview Programming Example Terahertz StepScan and FastScan - Readme (01.06.2016)
------------------------------------------------------------------------------------------------


Description:
------------

"Programming Example Terahertz StepScan and FastScan" is a simple programming example written in LabView (Version LabView 2013).
It demonstrates how to use the API of the DLC smart of TOPTICAs TeraScan/TeraBeam cw Terahertz Systems.

The program allows you to set the terahertz frequency and readout the lock-in value (i.e., the terahertz photocurrent).
Moreover, the program can record and display a terahertz spectrum by performing either a step scan or a "Fast Scan" of the terahertz frequency and sampling the lock-in values (the terahertz photocurrent).
Additionally, certain parameters like the Tx bias voltage or the lock-in integration time can be set.

The example includes a set of basic VIs for the communication with the DLC smart.

The program uses the following parameters/commands, see "TeraScan / TeraBeam REMOTE COMMAND REFERENCE":
general:system-type,
general:fw-ver,
laser-operation:emission-global-enable,
frequency:frequency-set,
frequency:frequency-min,
frequency:frequency-max,
frequency:frequency-step,
frequency:frequency-scan-mode-fast,
frequency:fast-scan-start,
frequency:fast-scan-stop,
frequency:fast-scan-isscanning,
frequency:fast-scan-get-data,
lockin:integration-time,
lockin:mod-out-set-to-default,
lockin:mod-out-set-to-zero,
lockin:mod-out-offset,
lockin:mod-out-amplitude,
lockin:lock-in-reset,
lockin:lock-in-value



Operation of the example program:
---------------------------------

1.) "IP Address of DLC smart":

Enter the IP address of the DLC smart here, e.g. "192.168.54.80".

2.) "Connect to DLC smart":

Push "Connect to DLC smart" in order to get a connection with the DLC smart.

2.) "Laser Emission On/Off":

You can use this button to switch On/Off laser emission.

3.) "Send All Values to DLC smart":

Since this is only a simple example program, it does not query the parameters of the DLC smart.
Therefore, the values of the LabView controls can differ from the parameter values in the DLC smart.
You can use the button "Send All Values to DLC smart" to send the actual values of all LabView controls to the DLC smart.

4.) "Frequency (GHz)":

Sets the terahertz frequency.

5.) "Sampling":

When the "Sampling"-Button is pressed, the terahertz signal (i.e. the THz photocurrent) is sampled for a fixed terahertz frequency.

6.) "Scan Up" / "Scan Down":

With these buttons a frequency scan is started from the momentary frequency.
The scan range is specified by "Min (GHz)", "Max (GHz)" and "Step (GHz)".
For starting the scan, the momentary frequency has to be within the specified range.
If "Continuously" is unchecked, the scan stops at the end of the scan range.
If "Continuously" is checked, the scan direction is inverted at the end of the range an the scan continues until it is stopped manually (e.g. by releasing the "Scan Up"/"Scan Down" button).
If "Fast Scan" is unchecked, the scan is controlled by LabView: The frequency is scanned step-by-step and each data point is readout and displayed.
If "Fast Scan" is checked, a fast scan is performed in the DLC smart.

7.) "Transimp. Amp. Gain":

Enter the gain value of your transimpedance amplifier.
This factor is used to correctly calculate the photocurrent.

8.) "Integration Time (ms)":

Sets the integration time of the lock-in.

9.) "Set Bias to Default", "Set Bias to Zero", "Tx Bias Offset (V)", "Tx Bias Amplitude (V)":

Use these controls to set the transmitter bias offset and amplitude.
Be careful! The allowed maximum voltages for the photomixers must not be exceeded!

10.) "Clear Graph":

Deletes all data in the plots.

11.) "Save Graph":

Saves the recorded data to file.
