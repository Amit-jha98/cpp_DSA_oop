
---

## Module 1: Diode Circuits

### P-N Junction Diode

A P-N junction diode is a fundamental two-terminal semiconductor device formed by joining a P-type semiconductor (rich in holes due to acceptor impurities like Boron) and an N-type semiconductor (rich in electrons due to donor impurities like Phosphorus). At the junction, diffusion of electrons and holes creates a depletion region devoid of free carriers, acting as a barrier.

The diode operates in two primary modes: **forward bias** and **reverse bias**. In forward bias (anode positive with respect to cathode), the depletion region narrows, allowing current to flow after surpassing a threshold voltage (typically 0.7V for silicon diodes). In reverse bias (anode negative), the depletion region widens, restricting current to a minimal leakage value until breakdown voltage is reached, at which point a large current can flow, possibly damaging the device if not properly controlled.

The I-V characteristic of a diode is exponential in the forward region, as described by the Shockley equation: \( I = I_s (e^{V/(nV_T)} - 1) \), where \( I_s \) is the saturation current and \( V_T \) is the thermal voltage. In the reverse region, current remains nearly constant and small, up to the breakdown point.

Equivalent circuit models for diodes include the ideal model (perfect conductor in forward, perfect insulator in reverse), the practical model (includes threshold voltage and forward resistance), and the complete model (adds junction capacitance and temperature effects).

### Rectifiers

Rectifiers are circuits that convert alternating current (AC) into direct current (DC). The simplest is the half-wave rectifier, which uses a single diode to allow only one half-cycle (positive or negative) of AC to pass through, blocking the other half. The output of a half-wave rectifier is a pulsating DC with an average voltage of \( V_{avg} = V_m/\pi \) (where \( V_m \) is the peak input voltage).

Full-wave rectifiers (center-tapped or bridge configurations) utilize both halves of the AC cycle, providing a higher average output and better efficiency. The bridge rectifier uses four diodes in a specific arrangement, eliminating the need for a center-tapped transformer and providing a lower Peak Inverse Voltage (PIV) requirement for each diode.

Important parameters for rectifiers include the ripple factor (which measures the AC content in DC output), PIV (the maximum reverse voltage a diode must withstand), efficiency (ratio of DC power to AC input power), and transformer utilization factor (TUF), which indicates how effectively the transformer is used.

### Zener Diode

A zener diode is a special type of diode designed to operate in the reverse breakdown region without damage. It maintains a nearly constant voltage across its terminals, making it invaluable for voltage regulation and reference applications. The sharp breakdown occurs due to either the zener effect (predominant below 5V) or avalanche effect (above 5V). Zener diodes are heavily doped to achieve this property.

Key characteristics include zener voltage (Vz), zener current (Iz), and dynamic resistance (rz) in the breakdown region. Applications extend to voltage regulation, protection circuits, and waveform shaping.

### Clipping Circuits

Clipping circuits are used to "clip" or remove portions of a signal voltage above or below certain levels, using diodes and reference voltages. Positive clippers remove the positive part of the input waveform, while negative clippers remove the negative part. Dual clippers can limit both ends of the waveform, producing an output constrained within a defined amplitude range. Clipping is essential in waveform shaping, noise reduction, and signal protection.

### Clamping Circuits

Clamping circuits shift the DC level of a signal without altering its shape. They use a combination of diodes and capacitors. A positive clamper shifts the entire waveform upward, making the minimum voltage equal to zero or another reference level, while a negative clamper shifts it downward. Applications include DC restoration in TV receivers and voltage level shifting in analog circuits.

---

## Module 2: BJT Circuits

### BJT Structure and I-V Characteristics

A Bipolar Junction Transistor (BJT) is a three-layer device, either NPN or PNP, consisting of emitter, base, and collector regions. The emitter is heavily doped to supply charge carriers (electrons or holes), the base is thin and lightly doped to allow carrier passage, and the collector is moderately doped with a large area for heat dissipation.

BJTs operate in three modes:
- **Cut-off:** Both junctions reverse-biased; very little current flows.
- **Active:** Emitter-base junction forward-biased, collector-base reverse-biased; used for amplification.
- **Saturation:** Both junctions forward-biased; maximum current flows, used for switching.

The input (base-emitter) characteristic resembles a forward-biased diode, with current rising exponentially after crossing a threshold voltage. Output (collector-emitter) characteristics show regions for active, saturation, and cut-off operation, each corresponding to different transistor applications (amplification or switching).

### BJT as Switch

When used as a switch, the BJT operates in either cut-off (OFF state) or saturation (ON state). In the OFF state, base-emitter voltage is below threshold, resulting in negligible collector current and high resistance. In the ON state, base-emitter voltage is sufficient to drive the transistor into saturation, leading to low collector-emitter voltage and significant current flow. Switching speed is influenced by charge storage in the base.

### BJT as Amplifier

For amplification, the transistor is biased in the active region. The operating point (Q-point) is carefully chosen for linear, distortion-free amplification. Small changes in base current produce large changes in collector current, providing current and voltage gain. Distortions can arise from improper biasing, frequency limitations, or non-linearities.

### Small-Signal Model

Small-signal models, such as the hybrid-π or h-parameter models, are used to analyze BJTs under small input variations. Parameters like input resistance, transconductance, output resistance, and capacitances are considered, alongside temperature effects (e.g., VBE decreases with temperature, β increases).

### Biasing Circuits

Biasing circuits establish the correct Q-point for BJTs. Fixed bias is simple but thermally unstable. Collector-to-base bias introduces negative feedback for better stability. Voltage divider bias is most stable and commonly used, as it is less sensitive to changes in β and provides good temperature compensation.

### Common Configurations

BJTs can be configured as common emitter (CE), common base (CB), or common collector (CC). The CE configuration provides high voltage and power gain with phase inversion, CB offers high-frequency response, and CC is used for impedance matching due to its high input and low output impedance.

### Current Mirror

A current mirror uses matched transistors to copy (mirror) a reference current to another branch of a circuit. Variations like Wilson, Widlar, and cascode mirrors provide improved accuracy, different output levels, or higher output impedance. They are vital in analog integrated circuits for biasing and as active loads.

---

## Module 3: MOSFET Circuits

### MOSFET Structure and I-V Characteristics

A Metal-Oxide-Semiconductor Field Effect Transistor (MOSFET) consists of source, drain, gate, and body terminals. The gate is insulated from the channel by a thin oxide layer, resulting in extremely high input resistance.

MOSFETs come in enhancement mode (normally off, channel forms when gate voltage exceeds threshold) and depletion mode (normally on, channel exists at zero gate voltage). They operate in three regions:
- **Cut-off:** Gate-source voltage below threshold, no current flows.
- **Triode (Linear):** Gate-source voltage above threshold and drain-source voltage low; acts as a voltage-controlled resistor.
- **Saturation (Active):** Gate-source voltage above threshold and drain-source voltage high; current is primarily controlled by gate voltage.

The transfer characteristic (ID vs VGS) and output characteristic (ID vs VDS at different VGS) define MOSFET operation, with a square-law relationship in saturation.

### MOSFET as Switch

In digital circuits, MOSFETs are widely used as switches. In the OFF state, they offer very high resistance, while in the ON state (triode region), they have low ON resistance. Switching speed is determined by the time required to charge and discharge the gate capacitance.

### MOSFET as Amplifier

For amplification, MOSFETs are biased in the saturation region. Common source amplifiers provide high voltage gain with phase inversion, common gate amplifiers offer high-frequency operation, and common drain (source follower) amplifiers are used for impedance matching.

### Small Signal Model

The small-signal model includes key parameters such as transconductance (gm), output resistance (ro), and capacitances (Cgs, Cgd, Cds). Frequency response is mainly limited by these intrinsic capacitances, especially in high-frequency applications.

### Biasing Circuits

Voltage divider bias is the most stable and popular for MOSFETs, using resistors to set the gate voltage and a source resistor for negative feedback. Current source biasing, often implemented with current mirrors, provides excellent stability and is common in integrated circuits.

### High-Frequency Equivalent Circuit

At high frequencies, parasitic capacitances and Miller effect cause gain reduction and phase shift. Cascode configurations and compensation techniques such as neutralization and impedance matching are used to improve frequency response and stability.

---

## Module 4: Differential, Multistage, and Op-Amps

### Differential Amplifier

A differential amplifier amplifies the difference between two input signals, rejecting common-mode noise and interference. It consists of two identical transistors (or MOSFETs) with shared emitter or source current. Key parameters include differential gain (Ad), common mode gain (Ac), and Common Mode Rejection Ratio (CMRR). High CMRR and DC stability make differential amplifiers essential in analog circuits.

### Power Amplifiers

Power amplifiers are classified by conduction angle:
- **Class A:** Conducts for the entire cycle, best linearity, lowest efficiency.
- **Class B:** Conducts for half the cycle, better efficiency, but with crossover distortion.
- **Class AB:** Conducts slightly more than half, balancing distortion and efficiency; common in audio applications.
- **Class C:** Conducts for less than half, high efficiency, used in RF circuits.

Performance parameters include efficiency, distortion, power output, and frequency response.

### Multistage Amplifier

Cascading multiple amplifier stages increases gain but narrows bandwidth and may introduce more noise or distortion. Coupling methods include RC (simple, limited low-frequency response), transformer (good impedance matching), and direct coupling (excellent frequency response, but susceptible to DC drift).

### Operational Amplifier (Op-Amp)

An op-amp is a high-gain, differential-input, single-ended output amplifier. Ideally, it has infinite gain, input impedance, and bandwidth, with zero output impedance and offset. Practically, parameters are finite but still very high, making op-amps versatile for a wide range of applications. Internal structure includes differential input, high-gain intermediate, and output buffer stages.

---

## Module 5: Linear Applications of Op-Amp

### Amplifiers

- **Inverting Amplifier:** Input signal applied to the inverting terminal through a resistor, with feedback from output to inverting terminal. Provides voltage gain \( A_v = -R_f / R_{in} \), inverts the signal, and has high input impedance.
- **Non-Inverting Amplifier:** Input applied to non-inverting terminal, offering gain \( A_v = 1 + R_f / R_{in} \) without inversion and very high input impedance.
- **Voltage Follower:** Unity gain, non-inverting configuration, used for buffering and impedance matching.

### Differential & Instrumentation Amplifier

Differential amplifiers amplify the difference between two inputs while rejecting common-mode signals. Instrumentation amplifiers, built from multiple op-amps, provide high gain, excellent CMRR, high input impedance, low drift, and are commonly used in precision measurement systems.

### Integrator

An op-amp integrator uses a resistor at the input and a capacitor in the feedback path, providing an output proportional to the time integral of the input. It's widely used in waveform generation, analog computation, and signal filtering.

### Active Filters

Active filters use op-amps to implement low pass, high pass, and band pass functions without the need for inductors. They offer gain, high input impedance, low output impedance, and easy tuning. Different filter responses (Butterworth, Chebyshev, Bessel) cater to various application needs.

### PID Controllers

PID controllers combine proportional, integral, and derivative actions for precise process control. Proportional control provides fast response, integral eliminates steady-state error, and derivative improves transient response. Tuning methods adjust the contribution of each term for optimal performance.

### Lead/Lag Compensators

Lead compensators improve transient response and stability by adding phase lead, while lag compensators enhance steady-state accuracy and disturbance rejection. Lead-lag compensators combine the benefits but require more complex tuning.

### Voltage Regulators

Linear regulators maintain a constant output voltage using a series or shunt element, offering moderate efficiency. Switching regulators (buck, boost, buck-boost) use high-speed switches and inductors/capacitors for high-efficiency voltage conversion.

### Oscillators

Oscillators generate periodic waveforms without external input. The Wien bridge oscillator uses an RC network for audio frequencies, while phase shift oscillators employ multiple RC stages. The Barkhausen criterion defines conditions for sustained oscillation.

### Analog to Digital Converter (ADC)

ADCs convert analog signals into digital form via sampling, quantization, and encoding. Types include flash (fast), successive approximation (balanced speed and accuracy), dual slope (high accuracy), and delta-sigma (high resolution). Key parameters are resolution, sampling rate, accuracy, and conversion time.

---

## Module 6: Nonlinear Applications of Op-Amp

### Hysteretic Comparator (Schmitt Trigger)

A Schmitt trigger uses positive feedback to introduce hysteresis, providing two distinct threshold levels (upper and lower) for switching. This prevents false triggering due to noise and produces clean, fast transitions, making it ideal for noise filtering and waveform shaping.

### Zero Crossing Detector

This circuit outputs a change whenever the input crosses zero volts, making it essential for AC signal measurement, frequency counting, and phase control. High gain enables rapid transitions, though practical designs must mitigate noise and offset errors.

### Wave Generators

- **Square Wave Generator:** Uses an op-amp in an astable multivibrator configuration to produce a square waveform.
- **Triangular Wave Generator:** Integrates a square wave to produce a linear, triangular output.
- **Sawtooth Generator:** Produces an asymmetric waveform for sweep and timing applications.

### Precision Rectifier

A precision rectifier overcomes the 0.7V diode drop using op-amp feedback, allowing accurate rectification of small signals. Full-wave precision rectifiers and peak detectors are used for signal processing and measurement.

### Monostable Multivibrator

This one-shot pulse generator produces a single output pulse of specified width in response to a trigger input. The pulse width is determined by RC timing components, widely used in timing and digital circuits.

---
---

## 📗 Module 1: Diode Circuits

| **Formula Name**               | **Formula Expression**               | **Description**                               |
| :----------------------------- | :----------------------------------- | :-------------------------------------------- |
| Diode I-V Characteristic       | $I = I_s \left(e^{V/V_T} - 1\right)$ | Current-voltage relationship of a diode       |
| Half-Wave Rectifier DC Output  | $V_{dc} = \frac{V_m}{\pi}$           | DC output voltage for half-wave rectification |
| Half-Wave Rectifier RMS Output | $V_{rms} = \frac{V_m}{2}$            | RMS output voltage for half-wave              |
| Full-Wave Rectifier DC Output  | $V_{dc} = \frac{2V_m}{\pi}$          | DC output voltage for full-wave rectification |
| Full-Wave Rectifier RMS Output | $V_{rms} = \frac{V_m}{\sqrt{2}}$     | RMS output voltage for full-wave              |
| Peak Inverse Voltage (PIV) HWR | $PIV = V_m$                          | Max reverse voltage diode must withstand      |
| Peak Inverse Voltage (PIV) FWR | $PIV = 2V_m$                         | Max reverse voltage for full-wave             |

---

## 📘 Module 2: BJT Circuits

| **Formula Name**            | **Formula Expression**             | **Description**                          |
| :-------------------------- | :--------------------------------- | :--------------------------------------- |
| Collector Current           | $I_C = \beta I_B$                  | BJT collector current                    |
| Emitter Current             | $I_E = I_B + I_C$                  | Emitter current relation                 |
| BJT DC Load Line            | $V_{CE} = V_{CC} - I_C R_C$        | DC operating point relation              |
| Voltage Gain (CE Amplifier) | $A_v = -\frac{g_m R_C}{1+g_m R_E}$ | Voltage gain for CE amplifier            |
| Transconductance            | $g_m = \frac{I_C}{V_T}$            | Ratio of output current to input voltage |
| Input Resistance (rπ)       | $r_{\pi} = \frac{\beta V_T}{I_C}$  | Small signal input resistance            |
| Output Resistance           | $r_o = \frac{V_A + V_{CE}}{I_C}$   | Output resistance due to Early effect    |

---

## 📙 Module 3: MOSFET Circuits

| **Formula Name**            | **Formula Expression**                                             | **Description**                          |
| :-------------------------- | :----------------------------------------------------------------- | :--------------------------------------- |
| MOSFET Cutoff Region        | $I_D = 0$                                                          | No current when $V_{GS} < V_{th}$        |
| MOSFET Linear Region        | $I_D = k\left[(V_{GS} - V_{th})V_{DS} - \frac{V_{DS}^2}{2}\right]$ | For $V_{DS} < V_{GS} - V_{th}$           |
| MOSFET Saturation Region    | $I_D = \frac{k}{2}(V_{GS} - V_{th})^2$                             | For $V_{DS} \geq V_{GS} - V_{th}$        |
| Transconductance            | $g_m = \frac{2I_D}{V_{GS} - V_{th}}$                               | Ratio of output current to gate voltage  |
| Input Resistance            | Very High                                                          | Due to insulated gate                    |
| Voltage Gain (CS Amplifier) | $A_v = -g_m R_D$                                                   | Voltage gain for common-source amplifier |

---

## 📕 Module 4: Differential, Multi-Stage & Op-Amps

| **Formula Name**       | **Formula Expression**     | **Description**                           |
| :--------------------- | :------------------------- | :---------------------------------------- |
| Differential Gain      | $A_d = \frac{g_m R_C}{2}$  | Gain for differential amplifier           |
| CMRR                   | $CMRR = \frac{A_d}{A_c}$   | Common mode rejection ratio               |
| Slew Rate              | $SR = \frac{dV_{out}}{dt}$ | Maximum rate of change of output          |
| Gain Bandwidth Product | $GBP = A_{OL} \times f_H$  | Product of gain and high frequency cutoff |

---

## 📒 Module 5: Linear Applications of Op-Amps

| **Formula Name**               | **Formula Expression**                               | **Description**                     |
| :----------------------------- | :--------------------------------------------------- | :---------------------------------- |
| Inverting Amplifier Gain       | $A_v = -\frac{R_f}{R_{in}}$                          | Gain for inverting op-amp           |
| Non-Inverting Amplifier Gain   | $A_v = 1 + \frac{R_f}{R_{in}}$                       | Gain for non-inverting op-amp       |
| Integrator Output              | $V_{out} = -\frac{1}{RC} \int V_{in} dt$             | Integrates input signal             |
| Differentiator Output          | $V_{out} = -RC \frac{dV_{in}}{dt}$                   | Differentiates input signal         |
| Instrumentation Amplifier Gain | $A_v = \left(1+\frac{2R}{R_G}\right)\frac{R_3}{R_2}$ | High gain differential amplifier    |
| Wein Bridge Oscillator Freq.   | $f = \frac{1}{2\pi RC}$                              | Frequency of Wein bridge oscillator |

---

## 📓 Module 6: Non-Linear Applications of Op-Amps

| **Formula Name**              | **Formula Expression**                                       | **Description**                                |
| :---------------------------- | :----------------------------------------------------------- | :--------------------------------------------- |
| Hysteresis Comparator         | Depends on upper/lower threshold voltages                    | Comparator with hysteresis                     |
| Zero Crossing Detector Output | Switches when $V_{in} = 0$                                   | Changes output at zero input                   |
| Square Wave Generator Freq.   | $f = \frac{1}{2RC \ln \left(\frac{1+\beta}{1-\beta}\right)}$ | Frequency depends on resistor-capacitor values |
| Triangular Wave Generator     | Integrates square wave to produce triangle                   | Produces triangular output from integrator     |
| Precision Rectifier Output    | Follows input for positive half cycles                       | Accurate rectification at low voltages         |
| Monostable Multivibrator Time | $T = 0.693 RC$                                               | Output pulse width in monostable operation     |

---



