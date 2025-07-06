## 📖 ESC 301: Analog Electronic Circuits

**Complete Detailed Study Notes**

---

# 📚 Module 1: Diode Circuits 

---

## ✅ P-N Junction Diode

### 🔬 Detailed Theory:

* **Definition:** A semiconductor device formed by joining a p-type and an n-type semiconductor through a diffusion process, creating a depletion region at the junction.

* **Physical Structure:**
  - P-type: Acceptor atoms (Boron), holes are majority carriers
  - N-type: Donor atoms (Phosphorus), electrons are majority carriers
  - Depletion region: Area with no mobile charge carriers

* **Symbol:**
```
Anode (P) →|← Cathode (N)
```

* **Operation Modes:**

  * **Forward Bias (Anode +, Cathode −):**
    - Reduces depletion region width
    - Current flows after threshold voltage (Vγ = 0.7V for Si, 0.3V for Ge)
    - Exponential current-voltage relationship
    - Low forward resistance (≈ 1-10Ω)
  
  * **Reverse Bias (Anode −, Cathode +):**
    - Increases depletion region width
    - Very small leakage current (nA to μA range)
    - High reverse resistance (MΩ range)
    - Breakdown occurs at reverse breakdown voltage

### 📊 I-V Characteristics:

* **Forward region:** Exponential rise beyond cut-in voltage following Shockley equation
* **Reverse region:** Small leakage current (Is) until breakdown voltage (VBR)
* **Breakdown region:** Avalanche or Zener breakdown, current increases rapidly

### 🏗️ Equivalent Circuit Models:

* **Ideal Model:** Perfect switch (0V forward, infinite reverse resistance)
* **Practical Model:** Includes threshold voltage and forward resistance
* **Complete Model:** Includes junction capacitance and temperature effects

---

## ✅ Rectifiers

### 🔬 Detailed Theory:

**Purpose:** Convert AC voltage to pulsating DC voltage

### **Half-Wave Rectifier:**

* **Operation:**
  - Uses single diode in series with load
  - Conducts only during positive half-cycle
  - Negative half-cycle is blocked
  - Output frequency = Input frequency

* **Characteristics:**
  - Peak output voltage: Vm - Vd
  - Average output voltage: Vm/π
  - RMS output voltage: Vm/2
  - Peak Inverse Voltage (PIV): Vm

### **Full-Wave Rectifiers:**

* **Center-Tapped Rectifier:**
  - Uses 2 diodes with center-tapped transformer
  - Each diode conducts alternately
  - PIV = 2Vm
  - Better transformer utilization than half-wave

* **Bridge Rectifier:**
  - Uses 4 diodes in bridge configuration
  - No center-tapped transformer required
  - PIV = Vm (lowest among all rectifiers)
  - Highest efficiency

### **Key Performance Parameters:**

* **Ripple Factor (r):** Measure of AC content in DC output
* **Peak Inverse Voltage (PIV):** Maximum reverse voltage across diode
* **Efficiency (η):** Ratio of DC power to AC power
* **Transformer Utilization Factor (TUF):** Effectiveness of transformer usage

---

## ✅ Zener Diode

### 🔬 Detailed Theory:

* **Operation Principle:**
  - Designed to operate in reverse breakdown region
  - Maintains constant voltage across terminals
  - Two breakdown mechanisms: Zener effect (<5V) and Avalanche effect (>5V)

* **Construction:**
  - Heavily doped P-N junction
  - Sharp breakdown characteristics
  - Low dynamic resistance in breakdown region

* **Symbol:** Standard diode symbol with bent cathode line

* **Applications:**
  - Voltage regulation circuits
  - Reference voltage sources
  - Overvoltage protection
  - Clipping circuits

* **Key Parameters:**
  - Zener voltage (Vz): Breakdown voltage
  - Zener current (Iz): Current in breakdown region
  - Dynamic resistance (rz): Slope of V-I curve in breakdown

---

## ✅ Clipping Circuits

### 🔬 Detailed Theory:

* **Purpose:** Remove or "clip" portions of input waveform above or below specified levels

* **Types:**

  * **Positive Clipper:**
    - Removes positive portion of input signal
    - Uses diode in reverse bias during positive half-cycle
    - Output limited to reference voltage level

  * **Negative Clipper:**
    - Removes negative portion of input signal
    - Uses diode in reverse bias during negative half-cycle

  * **Dual/Combinational Clipper:**
    - Clips both positive and negative portions
    - Uses two diodes with different reference levels
    - Creates limited amplitude output

* **Applications:**
  - Waveform shaping
  - Amplitude limiting
  - Noise reduction
  - Protection circuits

---

## ✅ Clamping Circuits

### 🔬 Detailed Theory:

* **Purpose:** Shift DC level of input signal without changing its shape

* **Operation Principle:**
  - Uses diode and capacitor combination
  - Capacitor charges during one half-cycle
  - Stored charge shifts the DC level of entire waveform

* **Types:**

  * **Positive Clamper:**
    - Shifts input signal upward
    - Minimum level of output becomes 0V or reference level
    - Diode conducts during negative half-cycle

  * **Negative Clamper:**
    - Shifts input signal downward
    - Maximum level of output becomes 0V or reference level
    - Diode conducts during positive half-cycle

* **Applications:**
  - DC restoration in TV receivers
  - Voltage level shifting
  - Biasing circuits

---

# 📚 Module 2: BJT Circuits 

---

## ✅ BJT Structure and I-V Characteristics

### 🔬 Detailed Theory:

* **Physical Structure:**
  - Three-layer sandwich: NPN or PNP
  - Three terminals: Emitter (E), Base (B), Collector (C)
  - Two junctions: Base-Emitter (BE) and Base-Collector (BC)

* **Doping Levels:**
  - Emitter: Heavily doped (high carrier concentration)
  - Base: Lightly doped and thin (≈1μm)
  - Collector: Moderately doped, largest area

* **Operating Modes:**

  * **Cut-off Mode:**
    - Both junctions reverse biased
    - No current flow (IC ≈ IB ≈ 0)
    - Transistor acts as open switch

  * **Active Mode:**
    - BE forward biased, BC reverse biased
    - Normal amplification region
    - IC = βIB (β = current gain)

  * **Saturation Mode:**
    - Both junctions forward biased
    - Maximum current flow
    - Transistor acts as closed switch

### 📈 I-V Characteristics:

* **Input Characteristics (IB vs VBE):**
  - Similar to forward-biased diode
  - Exponential relationship
  - Base current increases rapidly after VBE > 0.7V

* **Output Characteristics (IC vs VCE):**
  - Different curves for different IB values
  - Active region: IC relatively constant
  - Saturation region: IC increases with VCE
  - Cutoff region: IC ≈ 0

---

## ✅ BJT as Switch

### 🔬 Detailed Theory:

* **Cut-off Region (OFF):**
  - VBE < 0.7V
  - IC ≈ 0, VCE ≈ VCC
  - High resistance path (MΩ)
  - Power dissipation ≈ 0

* **Saturation Region (ON):**
  - VBE > 0.7V, sufficient base current
  - IC ≈ VCC/RC, VCE ≈ 0.2V
  - Low resistance path (few Ω)
  - Switching speed limited by charge storage

* **Switching Parameters:**
  - Turn-on time: Time to reach 90% of final value
  - Turn-off time: Time to fall to 10% of initial value
  - Storage time: Time to remove stored charge

---

## ✅ BJT as Amplifier

### 🔬 Detailed Theory:

* **Operating Point (Q-point):**
  - Established in active region
  - Determines DC operating conditions
  - Critical for distortion-free amplification

* **Amplification Mechanism:**
  - Small AC signal superimposed on DC bias
  - Base current variations control collector current
  - Current gain: β = IC/IB (typically 50-300)
  - Voltage gain depends on circuit configuration

* **Distortion Types:**
  - Amplitude distortion: Clipping due to improper biasing
  - Frequency distortion: Variation in gain with frequency
  - Phase distortion: Non-linear phase response

---

## ✅ Small-Signal Model

### 🔬 Detailed Theory:

* **Hybrid-π Model:**
  - rπ = βre (input resistance)
  - gm = IC/VT (transconductance)
  - ro = VA/IC (output resistance)
  - Cπ, Cμ (junction capacitances)

* **h-Parameter Model:**
  - hie = input resistance
  - hfe = forward current gain
  - hre = reverse voltage gain
  - hoe = output conductance

* **Temperature Effects:**
  - VBE decreases by 2mV/°C
  - β increases with temperature
  - Thermal runaway possible

---

## ✅ Biasing Circuits

### 🔬 Detailed Theory:

* **Fixed Bias Circuit:**
  - Simple resistor from VCC to base
  - Poor thermal stability
  - β-dependent operating point
  - Suitable for switching applications

* **Collector-to-Base Bias:**
  - Negative feedback improves stability
  - Self-biasing action
  - Better than fixed bias
  - Moderate stability factor

* **Voltage Divider Bias:**
  - Most stable configuration
  - Independent of β variations
  - Temperature compensation possible
  - Widely used in practical circuits

* **Stability Factors:**
  - S = ∂IC/∂ICO (leakage current stability)
  - S' = ∂IC/∂VBE (voltage stability)
  - S'' = ∂IC/∂β (current gain stability)

---

## ✅ Common Configurations

### 🔬 Detailed Theory:

| Parameter | Common Emitter | Common Base | Common Collector |
|-----------|----------------|-------------|------------------|
| **Voltage Gain (Av)** | High (-50 to -500) | Medium (50-300) | ≈ 1 (0.95-0.99) |
| **Current Gain (Ai)** | High (β) | < 1 (≈ 0.98) | High (β+1) |
| **Power Gain (Ap)** | Very High | Medium | High |
| **Input Impedance (Zi)** | Medium (1-5kΩ) | Low (20-50Ω) | High (50-500kΩ) |
| **Output Impedance (Zo)** | High (10-100kΩ) | High (0.5-2MΩ) | Low (10-100Ω) |
| **Phase Shift** | 180° | 0° | 0° |
| **Frequency Response** | Limited by Miller effect | Best HF response | Good |

**Applications:**
- **CE:** General purpose amplifier, most common
- **CB:** High frequency amplifier, buffer
- **CC:** Impedance matching, buffer, driver

---

## ✅ Current Mirror

### 🔬 Detailed Theory:

* **Basic Principle:**
  - Uses matched transistors
  - Reference current determines output current
  - VBE of both transistors equal
  - Output current mirrors reference current

* **Types:**
  - **Simple Current Mirror:** Basic 2-transistor configuration
  - **Wilson Current Mirror:** Improved accuracy
  - **Widlar Current Mirror:** Different current levels
  - **Cascode Current Mirror:** High output impedance

* **Applications:**
  - Biasing circuits in operational amplifiers
  - Active loads in differential amplifiers
  - Constant current sources

---

# 📚 Module 3: MOSFET Circuits 

---

## ✅ MOSFET Structure and I-V Characteristics

### 🔬 Detailed Theory:

* **Physical Structure:**
  - Metal-Oxide-Semiconductor structure
  - Gate oxide (SiO2) provides isolation
  - Source, Drain, Gate, and Body terminals
  - Channel forms between source and drain

* **Types:**

  * **Enhancement Mode:**
    - Channel must be enhanced by gate voltage
    - Normally OFF device
    - VGS > Vth required for conduction
    - Most common in digital circuits

  * **Depletion Mode:**
    - Channel exists at VGS = 0
    - Normally ON device
    - Channel depleted by negative VGS
    - Used in special applications

* **Operating Regions:**

  * **Cut-off Region:**
    - VGS < Vth
    - ID ≈ 0
    - Channel not formed

  * **Triode/Linear Region:**
    - VGS > Vth and VDS < VGS - Vth
    - Channel acts as voltage-controlled resistor
    - Used in switching applications

  * **Saturation/Active Region:**
    - VGS > Vth and VDS > VGS - Vth
    - Constant current region
    - Used for amplification

### 📊 I-V Characteristics:

* **Transfer Characteristics:** ID vs VGS
* **Output Characteristics:** ID vs VDS for different VGS
* **Square-law relationship in saturation**

---

## ✅ MOSFET as Switch

### 🔬 Detailed Theory:

* **OFF State (Cut-off):**
  - VGS < Vth
  - ID ≈ 0
  - VDS ≈ VDD
  - Very high resistance (GΩ range)

* **ON State (Triode):**
  - VGS >> Vth
  - Low RDS(ON) (mΩ to Ω range)
  - VDS ≈ ID × RDS(ON)
  - Controlled by gate voltage

* **Switching Characteristics:**
  - Turn-on time: Depends on gate capacitance charging
  - Turn-off time: Depends on gate capacitance discharging
  - Switching losses: CV²f losses dominant
  - No storage time (unlike BJT)

---

## ✅ MOSFET as Amplifier

### 🔬 Detailed Theory:

* **Operating Point:**
  - Set in saturation region
  - VGS > Vth, VDS > VGS - Vth
  - Q-point determines small-signal parameters

* **Common Configurations:**

  * **Common Source (CS):**
    - High voltage gain
    - Input at gate, output at drain
    - 180° phase shift
    - Most common configuration

  * **Common Gate (CG):**
    - Low input impedance
    - High frequency response
    - No phase shift
    - Used in high-frequency circuits

  * **Common Drain (CD)/Source Follower:**
    - Unity voltage gain
    - High input impedance
    - Low output impedance
    - Buffer applications

---

## ✅ Small Signal Model

### 🔬 Detailed Theory:

* **Key Parameters:**
  - **gm (Transconductance):** ∂ID/∂VGS
  - **ro (Output resistance):** ∂VDS/∂ID
  - **gmb (Body transconductance):** ∂ID/∂VBS

* **Capacitances:**
  - **Cgs:** Gate-to-source capacitance
  - **Cgd:** Gate-to-drain capacitance (Miller capacitance)
  - **Cds:** Drain-to-source capacitance

* **Frequency Response:**
  - Limited by gate capacitances
  - Miller effect in CS amplifier
  - Transit frequency: fT = gm/(2π(Cgs + Cgd))

---

## ✅ Biasing Circuits

### 🔬 Detailed Theory:

* **Voltage Divider Bias:**
  - Most stable and commonly used
  - Gate voltage set by resistive divider
  - Source resistance provides negative feedback
  - Self-biasing action

* **Source Bias:**
  - Uses source resistor for bias
  - Simpler circuit
  - Good stability
  - Suitable for discrete circuits

* **Current Source Bias:**
  - Uses current mirror for biasing
  - Excellent stability
  - Used in integrated circuits
  - Higher complexity

---

## ✅ High-Frequency Equivalent Circuit

### 🔬 Detailed Theory:

* **Parasitic Capacitances:**
  - **Cgs:** Overlap capacitance + channel capacitance
  - **Cgd:** Overlap capacitance (Miller effect)
  - **Cds:** Junction capacitance

* **High-Frequency Effects:**
  - Gain reduction with frequency
  - Phase shift introduction
  - Miller effect in CS amplifier
  - Transit frequency limitations

* **Frequency Compensation:**
  - Cascode configuration
  - Neutralization techniques
  - Impedance matching

---

# 📚 Module 4: Differential, Multistage, and Op-Amps 

---

## ✅ Differential Amplifier

### 🔬 Detailed Theory:

* **Configuration:**
  - Two identical transistors
  - Common emitter resistor or current source
  - Symmetric design for optimal performance

* **Operation Modes:**
  - **Differential Mode:** V1 ≠ V2
  - **Common Mode:** V1 = V2
  - **Mixed Mode:** Combination of both

* **Key Parameters:**
  - **Differential Gain (Ad):** Gain for differential input
  - **Common Mode Gain (Ac):** Gain for common mode input
  - **CMRR:** Common Mode Rejection Ratio = Ad/Ac
  - **Input Offset Voltage:** DC voltage causing zero output

* **Advantages:**
  - High noise immunity
  - Temperature drift compensation
  - Excellent DC stability
  - High CMRR (60-120 dB)

---

## ✅ Power Amplifiers

### 🔬 Detailed Theory:

* **Classification by Conduction Angle:**

  * **Class A:**
    - Conduction angle: 360°
    - Q-point at center of load line
    - Maximum theoretical efficiency: 50%
    - Excellent linearity, high distortion immunity
    - High quiescent power consumption

  * **Class B:**
    - Conduction angle: 180°
    - Q-point at cutoff
    - Maximum theoretical efficiency: 78.5%
    - Requires push-pull configuration
    - Crossover distortion present

  * **Class AB:**
    - Conduction angle: 180° to 360°
    - Q-point slightly above cutoff
    - Efficiency: 50-78.5%
    - Reduced crossover distortion
    - Most common in audio amplifiers

  * **Class C:**
    - Conduction angle: <180°
    - Maximum theoretical efficiency: >78.5%
    - High distortion, used in RF applications
    - Requires tuned circuits

* **Performance Parameters:**
  - **Efficiency (η):** Po/Pin ratio
  - **Distortion:** THD, intermodulation distortion
  - **Power Output:** Maximum deliverable power
  - **Frequency Response:** Bandwidth limitations

---

## ✅ Multistage Amplifier

### 🔬 Detailed Theory:

* **Coupling Methods:**
  - **RC Coupling:** Simple, economical, limited low-frequency response
  - **Transformer Coupling:** Good impedance matching, frequency limitations
  - **Direct Coupling:** Excellent frequency response, DC drift problems

* **Cascade Effects:**
  - **Gain:** Overall gain = A1 × A2 × A3 × ...
  - **Bandwidth:** Reduced due to cascading
  - **Noise:** Noise figure degradation
  - **Distortion:** Accumulation of distortions

* **Design Considerations:**
  - Impedance matching between stages
  - Stability and oscillation prevention
  - Thermal drift compensation
  - Frequency response optimization

---

## ✅ Operational Amplifier

### 🔬 Detailed Theory:

* **Ideal Characteristics:**
  - **Open-loop gain (A):** Infinite
  - **Input impedance (Zi):** Infinite
  - **Output impedance (Zo):** Zero
  - **Bandwidth:** Infinite
  - **Offset voltage:** Zero
  - **CMRR:** Infinite

* **Practical Limitations:**
  - **Finite open-loop gain:** 10⁵ to 10⁶
  - **Input bias current:** nA to pA
  - **Input offset voltage:** mV range
  - **Finite bandwidth:** GBW product
  - **Slew rate:** V/μs limitations
  - **Output current:** Limited driving capability

* **Internal Structure:**
  - Differential input stage
  - High-gain intermediate stage
  - Output buffer stage
  - Compensation circuitry

---

# 📚 Module 5: Linear Applications of Op-Amp 

---

## ✅ Amplifiers

### 🔬 Detailed Theory:

* **Inverting Amplifier:**
  - **Configuration:** Input through Rin, feedback through Rf
  - **Gain:** Av = -Rf/Rin
  - **Input impedance:** Rin (due to virtual short)
  - **Output impedance:** Very low (≈0)
  - **Bandwidth:** Reduced by closed-loop gain
  - **Applications:** Signal amplification, sign inversion

* **Non-Inverting Amplifier:**
  - **Configuration:** Input to non-inverting terminal
  - **Gain:** Av = 1 + Rf/Rin
  - **Input impedance:** Very high (≈∞)
  - **Output impedance:** Very low (≈0)
  - **Bandwidth:** Higher than inverting amplifier
  - **Applications:** Buffer, impedance transformation

* **Voltage Follower:**
  - **Configuration:** Unity gain non-inverting amplifier
  - **Gain:** Av = 1
  - **Input impedance:** Very high
  - **Output impedance:** Very low
  - **Applications:** Impedance buffering, isolation

---

## ✅ Differential & Instrumentation Amplifier

### 🔬 Detailed Theory:

* **Differential Amplifier:**
  - **Configuration:** Two inputs, differential output
  - **Gain:** Ad = R2/R1 (for matched resistors)
  - **CMRR:** Limited by resistor matching
  - **Applications:** Noise rejection, sensor interfaces

* **Instrumentation Amplifier:**
  - **Configuration:** Three op-amp design
  - **Gain:** G = 1 + 2R1/RG
  - **CMRR:** Very high (>100 dB)
  - **Input impedance:** Very high
  - **Applications:** Precision measurements, medical instrumentation, strain gauge amplifiers

* **Advantages:**
  - Excellent CMRR
  - High input impedance
  - Low drift
  - Precise gain control

---

## ✅ Integrator

### 🔬 Detailed Theory:

* **Basic Integrator:**
  - **Configuration:** Capacitor in feedback, resistor at input
  - **Transfer function:** Vo = -(1/RC) ∫ Vin dt
  - **Frequency response:** -20 dB/decade slope
  - **Phase response:** -90° phase shift

* **Practical Integrator:**
  - **DC gain limitation:** Parallel resistor with capacitor
  - **Prevents saturation:** Limits DC gain
  - **Frequency response:** Integration above corner frequency

* **Applications:**
  - Waveform generation
  - Analog computation
  - Filter circuits
  - Signal processing

---

## ✅ Active Filters

### 🔬 Detailed Theory:

* **Advantages over Passive Filters:**
  - No inductor requirement
  - Gain possible
  - High input impedance
  - Low output impedance
  - Easy to tune

* **Filter Types:**

  * **Low Pass Filter:**
    - Passes low frequencies, attenuates high frequencies
    - **Sallen-Key topology:** Simple, good performance
    - **Multiple feedback:** Higher Q possible
    - **Cutoff frequency:** fc = 1/(2πRC)

  * **High Pass Filter:**
    - Passes high frequencies, attenuates low frequencies
    - **Cutoff frequency:** fc = 1/(2πRC)
    - **Roll-off:** 20 dB/decade for first-order

  * **Band Pass Filter:**
    - Passes specific frequency band
    - **Center frequency:** fo = 1/(2πRC)
    - **Bandwidth:** BW = fo/Q
    - **Quality factor:** Q determines selectivity

* **Filter Responses:**
  - **Butterworth:** Maximally flat passband
  - **Chebyshev:** Ripple in passband, sharp cutoff
  - **Bessel:** Linear phase response

---

## ✅ PID Controllers

### 🔬 Detailed Theory:

* **Proportional (P) Controller:**
  - **Output:** Kp × error
  - **Characteristics:** Fast response, steady-state error
  - **Gain:** Kp determines response speed

* **Integral (I) Controller:**
  - **Output:** Ki ∫ error dt
  - **Characteristics:** Eliminates steady-state error
  - **Time constant:** Ti = 1/Ki

* **Derivative (D) Controller:**
  - **Output:** Kd × d(error)/dt
  - **Characteristics:** Improves transient response
  - **Time constant:** Td = Kd

* **PID Controller:**
  - **Combined response:** P + I + D
  - **Tuning methods:** Ziegler-Nichols, Cohen-Coon
  - **Applications:** Process control, servo systems

---

## ✅ Lead/Lag Compensator

### 🔬 Detailed Theory:

* **Lead Compensator:**
  - **Phase:** Adds positive phase
  - **Frequency response:** Improves transient response
  - **Applications:** Stability improvement, speed enhancement

* **Lag Compensator:**
  - **Phase:** Adds negative phase
  - **Frequency response:** Improves steady-state accuracy
  - **Applications:** Error reduction, disturbance rejection

* **Lead-Lag Compensator:**
  - **Combined benefits:** Both transient and steady-state improvement
  - **Design complexity:** More parameters to tune

---

## ✅ Voltage Regulators

### 🔬 Detailed Theory:

* **Linear Regulators:**
  - **Series regulator:** Pass element in series
  - **Shunt regulator:** Pass element in parallel
  - **Regulation:** Maintains constant output voltage
  - **Efficiency:** Moderate (50-80%)

* **Switching Regulators:**
  - **Buck converter:** Step-down voltage
  - **Boost converter:** Step-up voltage
  - **Buck-boost:** Both step-up and step-down
  - **Efficiency:** High (80-95%)

* **Performance Parameters:**
  - **Line regulation:** Output change with input change
  - **Load regulation:** Output change with load change
  - **Ripple rejection:** AC component suppression

---

## ✅ Oscillators

### 🔬 Detailed Theory:

* **Oscillation Conditions:**
  - **Barkhausen criteria:** |βA| = 1 and phase shift = 0° or 360°
  - **Positive feedback:** Required for sustained oscillation
  - **Amplitude limiting:** Prevents saturation

* **Wien Bridge Oscillator:**
  - **Frequency:** fo = 1/(2πRC)
  - **Feedback network:** RC bridge circuit
  - **Amplitude control:** Automatic gain control
  - **Distortion:** Low THD possible
  - **Applications:** Audio frequency generation, test equipment

* **Phase Shift Oscillator:**
  - **Frequency:** fo = 1/(2π√6 RC)
  - **Phase shift:** 180° from RC network + 180° from amplifier
  - **Feedback:** Three RC stages provide 180° shift
  - **Applications:** Simple oscillator circuits

---

## ✅ Analog to Digital Converter (ADC)

### 🔬 Detailed Theory:

* **Conversion Process:**
  - **Sampling:** Discrete time sampling
  - **Quantization:** Discrete amplitude levels
  - **Encoding:** Binary representation

* **ADC Types:**
  - **Flash ADC:** Fastest, highest power
  - **Successive approximation:** Moderate speed, good accuracy
  - **Dual slope:** High accuracy, slow speed
  - **Delta-sigma:** High resolution, oversampling

* **Performance Parameters:**
  - **Resolution:** Number of bits
  - **Sampling rate:** Samples per second
  - **Accuracy:** INL, DNL specifications
  - **Conversion time:** Time for one conversion

---

# 📚 Module 6: Nonlinear Applications of Op-Amp 

---

## ✅ Hysteretic Comparator (Schmitt Trigger)

### 🔬 Detailed Theory:

* **Operation Principle:**
  - **Positive feedback:** Creates hysteresis
  - **Two threshold levels:** Upper and lower trigger points
  - **Switching action:** Abrupt output change
  - **Noise immunity:** Hysteresis prevents false triggering

* **Threshold Calculations:**
  - **Upper threshold:** VUT = (R1/(R1+R2)) × Vsat
  - **Lower threshold:** VLT = -(R1/(R1+R2)) × Vsat
  - **Hysteresis width:** ΔV = VUT - VLT

* **Applications:**
  - Noise filtering
  - Square wave generation
  - Level detection
  - Oscillator circuits

---

## ✅ Zero Crossing Detector

### 🔬 Detailed Theory:

* **Operation:**
  - **Threshold level:** 0V (or reference level)
  - **Output switching:** When input crosses zero
  - **High gain:** Small input changes cause large output changes
  - **Speed:** Limited by slew rate

* **Applications:**
  - AC zero-crossing detection
  - Frequency measurement
  - Phase control circuits
  - Power control systems

* **Practical Considerations:**
  - Noise sensitivity
  - Offset voltage effects
  - Input protection required

---

## ✅ Wave Generators

### 🔬 Detailed Theory:

* **Square Wave Generator:**
  - **Astable multivibrator:** Self-triggering
  - **Frequency:** f = 1/(2RC ln(1+2R1/R2))
  - **Duty cycle:** Controlled by circuit parameters
  - **Output:** Clean square wave with fast transitions

* **Triangular Wave Generator:**
  - **Integration:** Square wave integrated to triangular
  - **Dual op-amp:** Comparator + integrator
  - **Frequency:** Same as square wave input
  - **Linearity:** Excellent triangular waveform

* **Sawtooth Generator:**
  - **Asymmetric:** Different rise and fall times
  - **Applications:** Sweep circuits, CRO timebase

---

## ✅ Precision Rectifier

### 🔬 Detailed Theory:

* **Half-Wave Precision Rectifier:**
  - **Diode in feedback:** Eliminates forward voltage drop
  - **Precision:** Rectifies small AC signals
  - **Output:** Positive half-cycles only
  - **Advantage:** No 0.7V loss

* **Full-Wave Precision Rectifier:**
  - **Absolute value circuit:** |Vin| output
  - **Both half-cycles:** Converted to positive
  - **Complex circuit:** Multiple op-amps required
  - **Applications:** AC-DC conversion, signal processing

* **Peak Detector:**
  - **Capacitor storage:** Holds peak value
  - **Diode charging:** Charges during peaks
  - **Discharge:** Controlled by load resistance
  - **Applications:** Peak measurement, envelope detection

---

## ✅ Monostable Multivibrator

### 🔬 Detailed Theory:

* **Operation:**
  - **Trigger input:** Initiates output pulse
  - **Pulse width:** Determined by RC time constant
  - **Single pulse:** Returns to stable state
  - **Retriggerable:** Can be triggered during pulse

* **Pulse Width:** T = RC ln(1 + 2R1/R2)

* **Applications:**
  - Pulse generation
  - Timing circuits
  - Delay circuits
  - Digital systems

---

# 📊 Formula Reference Table

| **Category** | **Parameter** | **Formula** | **Units** |
|--------------|---------------|-------------|-----------|
| **Diode** | Forward Current | I = Is(e^(V/nVT) - 1) | A |
| | Thermal Voltage | VT = kT/q ≈ 26mV at 25°C | V |
| **Rectifier** | Half-Wave Avg Voltage | Vavg = Vm/π | V |
| | Half-Wave RMS Voltage | Vrms = Vm/2 | V |
| | Full-Wave Avg Voltage | Vavg = 2Vm/π | V |
| | Full-Wave RMS Voltage | Vrms = Vm/√2 | V |
| | Ripple Factor | r = √(Vrms/Vdc)² - 1 | - |
| | Efficiency | η = (Pdc/Pac) × 100% | % |
| **BJT** | Current Gain | β = IC/IB | - |
| | Transconductance | gm = IC/VT | S |
| | Input Resistance | rπ = β/gm | Ω |
| | Early Voltage | VA = IC × ro | V |
| **CE Amplifier** | Voltage Gain | Av = -gmRC | - |
| | Current Gain | Ai = β | - |
| | Power Gain | Ap = Av × Ai | - |
| **MOSFET** | Drain Current (Sat) | ID = (1/2)μnCox(W/L)(VGS-Vth)² | A |
| | Transconductance | gm = √(2μnCox(W/L)ID) | S |
| | Output Resistance | ro = 1/(λID) | Ω |
| **Op-Amp** | Inverting Gain | Av = -Rf/Rin | - |
| | Non-Inverting Gain | Av = 1 + Rf/Rin | - |
| | Gain-Bandwidth Product | GBW = Av × f3dB | Hz |
| | Slew Rate | SR = dVo/dt(max) | V/μs |
| **Filters** | Cutoff Frequency | fc = 1/(2πRC) | Hz |
| | Quality Factor | Q = fc/BW | - |
| | Damping Factor | ζ = 1/(2Q) | - |
| **Oscillators** | Wien Bridge Frequency | fo = 1/(2πRC) | Hz |
| | Phase Shift Frequency | fo = 1/(2π√6 RC) | Hz |
| **Power Amplifier** | Efficiency Class A | η = 25% (max 50%) | % |
| | Efficiency Class B | η = 78.5% (theoretical) | % |
| | Power Dissipation | PD = VCE × IC | W |
| **Comparator** | Hysteresis Width | ΔV = 2VsatR1/(R1+R2) | V |
| | Upper Threshold | VUT = VsatR1/(R1+R2) | V |
| **Integrator** | Output Voltage | Vo = -(1/RC)∫Vin dt | V |
| | Time Constant | τ = RC | s |
| **Differentiator** | Output Voltage | Vo = -RC(dVin/dt) | V |
| **Current Mirror** | Output Current | Io = Iref × (W/L)o/(W/L)ref | A |
| **Multivibrator** | Pulse Width | T = RC ln(1+2R1/R2) | s |
| | Frequency | f = 1/T | Hz |

---

## 📝 Important Constants

| **Constant** | **Symbol** | **Value** | **Units** |
|--------------|------------|-----------|-----------|
| Electron Charge | q | 1.602 × 10⁻¹⁹ | C |
| Boltzmann Constant | k | 1.381 × 10⁻²³ | J/K |
| Thermal Voltage (25°C) | VT | 25.85 | mV |
| Silicon Bandgap | Eg | 1.12 | eV |
| Electron Mobility (Si) | μn | 1350 | cm²/V·s |
| Hole Mobility (Si) | μp | 480 | cm²/V·s |
| Oxide Permittivity | εox | 3.9 × 8.854 × 10⁻¹⁴ | F/cm |

---

## 🎯 Key Design Equations

### **Amplifier Design:**
- **Voltage Gain:** Av = -gmRL
- **Input Impedance:** Zin = rπ || R1 || R2
- **Output Impedance:** Zout = RC || ro
- **Bandwidth:** BW = GBW/|Av|

### **Bias Design:**
- **Stability Factor:** S = (1+β)/(1+β(RB/(RB+RE)))
- **Thermal Stability:** ΔIC/ΔT = S × ΔICO/ΔT

### **Frequency Response:**
- **Miller Capacitance:** CM = Cgd(1+|Av|)
- **Gain-Bandwidth Product:** GBW = |Av| × f3dB
- **Slew Rate:** SR = Imax/Ccomp

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

