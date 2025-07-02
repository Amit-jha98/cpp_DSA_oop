
### Q 1(a)

**Question:**
For a base current of $I_B = 10\,\mu\text{A}$, what is the collector current $I_C$ in a common‑emitter transistor if $\beta_{dc}=100$?

* (i) 10 µA
* (ii) 100 µA
* (iii) 1 mA
* (iv) 10 mA

**Answer:** (iii) 1 mA

**Explanation:**
In the forward‐active (common‑emitter) region

$$
I_C \approx \beta\,I_B = 100 \times 10\,\mu\text{A} = 1000\,\mu\text{A} = 1\,\text{mA}.
$$

---

### Q 1(b)

**Question:**
An amplifier has open‑loop gain $A=-1000$ and a feedback factor $\beta=0.1$. If the open‑loop gain $A$ changes by 20% (due to temperature or device variations), what is the approximate percent change in the **closed‑loop** gain $A_F$?

* (i) 10%
* (ii) 5%
* (iii) 0.2%
* (iv) 0.01%

**Answer:** (iii) 0.2%

**Explanation:**
Closed‑loop gain with negative feedback is

$$
A_F = \frac{A}{1 + A\,\beta}.
$$

Loop gain $A\beta=1000\times0.1=100$. A 20% change in $A$ (i.e.\ $\Delta A/A=0.20$) produces roughly

$$
\frac{\Delta A_F}{A_F}\approx\frac{\Delta A}{1+A\beta}
=\frac{0.20}{1+100}\approx0.00198\approx0.2\%.
$$

Feedback divides variations by the factor $1+A\beta$.

---

### Q 1(c)

**Question:**
A trivalent impurity (e.g.\ aluminum in silicon) has how many valence electrons?

* (i) 4
* (ii) 5
* (iii) 6
* (iv) 3

**Answer:** (iv) 3

**Explanation:**
“Trivalent” means the atom contributes three valence electrons for bonding (e.g.\ Al has three outer‑shell electrons).

---

### Q 1(d)

**Question:**
Zener diodes are used primarily as …

* (i) Amplifiers
* (ii) Voltage regulators
* (iii) Rectifiers
* (iv) Oscillators

**Answer:** (ii) Voltage regulators

**Explanation:**
In reverse bias, a Zener diode holds its breakdown voltage nearly constant, making it ideal for voltage‐reference and regulation.

---

### Q 1(e)

**Question:**
The peak inverse voltage (PIV) rating of the diode used in a half‑wave rectifier is …

* (i) 2 V<sub>m</sub>
* (ii) V<sub>m</sub>/2
* (iii) V<sub>m</sub>
* (iv) V<sub>m</sub>/3

**Answer:** (iii) $V_m$

**Explanation:**
During the negative half‑cycle, the non‐conducting diode sees the full peak of the AC source, $V_m$.

---

### Q 1(f)

**Question:**
For every 10 °C increase in temperature, the reverse‐saturation current $I_S$ of a $p$–$n$ junction will increase by:

* (i) 10 times
* (ii) 2 times
* (iii) 4 times
* (iv) Remain same

**Answer:** (ii) 2 times

**Explanation:**
Empirically, silicon’s reverse saturation current roughly **doubles** for each 10 °C rise.

---

### Q 1(g)

**Question:**
A BJT transistor operates in which region when the base–emitter junction is forward‑biased and the base–collector junction is reverse‑biased?

* (i) Active region
* (ii) Saturation region
* (iii) Cutoff region
* (iv) Reverse‑active region

**Answer:** (i) Active region

**Explanation:**
Forward BE bias injects carriers; reverse BC bias collects them, giving the normal amplifying (active) mode.

---

### Q 1(h)

**Question:**
In an RC phase‑shift oscillator, the phase shift provided by each RC stage is:

* (i) 30°
* (ii) 45°
* (iii) 60°
* (iv) 90°

**Answer:** (iii) 60°

**Explanation:**
Three identical RC networks each shift by 60°, totaling 180°; the amplifier then provides the extra 180° to meet the loop phase‐shift requirement.

---

### Q 1(i)

**Question:**
If the PIV rating of a diode is exceeded,

* (i) the diode conducts poorly
* (ii) the diode is destroyed
* (iii) the diode behaves as a Zener diode
* (iv) None of the above

**Answer:** (ii) the diode is destroyed

**Explanation:**
Exceeding the reverse‐voltage rating causes avalanche breakdown and permanent damage.

---

### Q 1(j)

**Question:**
For a J‑FET with $I_{DSS}=9\,\text{mA}$ and pinch‑off voltage $V_P=-3.5\,\text{V}$, the drain current $I_D$ at $V_{GS}=0$ is:

* (i) 8 mA
* (ii) 9 mA
* (iii) 10 mA
* (iv) 11 mA

**Answer:** (ii) 9 mA

**Explanation:**
At $V_{GS}=0$, the J‑FET conducts its maximum (saturation) current $I_{D}=I_{DSS}$.

---


---

## Q.2 (a) Define the following:

### (i) Common‑Mode Rejection Ratio (CMRR)

**Definition:**
The Common‑Mode Rejection Ratio (CMRR) of an amplifier is the ratio of its differential gain $A_D$ (how much it amplifies the difference between the two inputs) to its common‑mode gain $A_{CM}$ (how much it inadvertently amplifies the voltage common to both inputs):

$$
\boxed{\mathrm{CMRR} = \frac{A_D}{A_{CM}}}
$$

Because we often work in decibels, it’s customary to express:

$$
\mathrm{CMRR}_{\rm dB} = 20\log_{10}\!\Bigl(\tfrac{A_D}{A_{CM}}\Bigr).
$$

* **Why it matters:** A high CMRR means the amplifier rejects any interference or noise that appears equally on both inputs (e.g.\ power‑line hum picked up by long leads).

---

### (ii) Gain–Bandwidth Product (GBW)

**Definition:**
For a single‑pole op‑amp whose open‑loop gain $A_{\rm OL}(f)$ rolls off at –20 dB/decade above its dominant pole $f_p$, the product of the low‑frequency gain $A_{\rm OL}(0)$ and that pole frequency is a constant:

$$
\boxed{\mathrm{GBW} = A_{\rm OL}(0)\times f_{p}}
$$

* **Closed‑loop use:** If you configure the amplifier for a closed‑loop gain $A_{CL}$, its –3 dB bandwidth $f_{CL}$ satisfies approximately

  $$
  A_{CL}\times f_{CL}\approx \mathrm{GBW}.
  $$

  Thus, boosting gain narrows bandwidth and vice versa.

---

### (iii) Slew Rate

**Definition:**
The slew rate (SR) of an op‑amp is the maximum rate at which its output voltage can change, typically given in V/µs:

$$
\boxed{\mathrm{SR} = \max\!\Bigl|\frac{dV_{\rm out}}{dt}\Bigr|}
$$

* **Practical implication:** If you ask the amplifier to produce a sine wave of peak amplitude $V_p$ at frequency $f$, you need

  $$
     \mathrm{SR} \;\ge\; 2\pi f \, V_p
  $$

  to avoid slew‑induced distortion (the tops of the waveform get “triangular” if SR is too low).

---

## Q.2 (b) State the Barkhausen condition for an electronic system to oscillate with feedback.

An electronic feedback loop will sustain steady sinusoidal oscillations at angular frequency $\omega_0$ if **both** of these conditions are met around the loop:

1. **Magnitude condition:**

   $$
   \bigl|A_{\rm OL}(j\omega_0)\,\beta(j\omega_0)\bigr| = 1
   $$

   That is, the loop‑gain is unity in magnitude.

2. **Phase condition:**

   $$
   \angle A_{\rm OL}(j\omega_0)\,\beta(j\omega_0) = 0^\circ \quad(\mathrm{mod}\;360^\circ)
   $$

   The total phase shift around the loop must be an integer multiple of $360^\circ$ so that the feedback is in phase with the input.

---
---

## Q.3 (a) Derive the expression for the stability factor for a fixed‑bias circuit with respect to $I_{C0}$, $V_{BE}$, and $\beta$.

### Circuit Description

A “fixed‑bias” (or base‑bias) BJT circuit looks like this:

```
   VCC
    │
   RB
    │
    └─► B
         │
        BE junction
         │
        E┴─┐
            └───┐
                │
               RC
                │
               VCC
```

* $R_B$ connects the base to $V_{CC}$.
* The emitter is directly grounded (no $R_E$).
* We include the transistor’s leakage current $I_{CBO}$ (reverse saturation from C→B with E open).

### Collector Current Equation

In forward‑active mode, and including leakage:

1. **Base loop:**

   $$
   \underbrace{V_{CC} - I_B\,R_B}_{\text{voltage at B}} \;=\; V_{BE}.
   $$

   Thus

   $$
     I_B \;=\;\frac{V_{CC}-V_{BE}}{R_B}.
   $$

2. **Collector current:**
   Two contributions to $I_C$:

   * The normal amplified base current, $\beta\,I_B$.
   * The amplified leakage current, $(1+\beta)\,I_{CBO}$, because leakage current at the base‑collector junction behaves like an extra base current of magnitude $I_{CBO}$, which also gets multiplied by $\beta$.

   Therefore:

   $$
   \boxed{\,I_C 
     = \beta\,I_B \;+\;(1+\beta)\,I_{CBO}
     = \beta\,\frac{V_{CC}-V_{BE}}{R_B}
       \;+\;(1+\beta)\,I_{CBO}\,.}
   $$

### Stability Factor $S$

The stability factor $S$ measures how sensitive $I_C$ is to changes in $I_{CBO}$:

$$
S \;=\;\frac{\partial I_C}{\partial I_{CBO}}.
$$

Differentiate the expression for $I_C$ with respect to $I_{CBO}$:

$$
\frac{\partial}{\partial I_{CBO}}\Bigl[\beta\,\tfrac{V_{CC}-V_{BE}}{R_B}
  + (1+\beta)\,I_{CBO}\Bigr]
= 0 + (1+\beta)
$$

So

$$
\boxed{\,S = 1 + \beta.}
$$

* **Interpretation:** The larger $\beta$ is, the more a small change in leakage current is amplified into $I_C$. Hence fixed‑bias is very unstable for high‑gain transistors.

---

## Q.3 (b) A voltage‑divider biased circuit has $R_1=39\,\mathrm{k}\Omega$, $R_2=82\,\mathrm{k}\Omega$, $R_C=3.3\,\mathrm{k}\Omega$, $R_E=1\,\mathrm{k}\Omega$, and $V_{CC}=18\,\mathrm{V}$. The silicon transistor used has $\beta=120$. Find the Q‑point and the stability factor.

### 1. Determine Thevenin equivalent at the base

* The divider supplies base bias:

  $$
  V_B^{\rm th}
    = V_{CC}\,\frac{R_2}{R_1 + R_2}
    = 18\,\mathrm{V}\times\frac{82}{39 + 82}
    \approx 18 \times 0.677 = 12.19\,\mathrm{V}.
  $$
* The Thevenin resistance:

  $$
  R_{th} = R_1 \parallel R_2
         = \frac{39\times82}{39+82}\,\mathrm{k}\Omega
         \approx \frac{3198}{121}\approx26.4\,\mathrm{k}\Omega.
  $$

### 2. Write node‑equations for base–emitter loop

Base node sees a small base current $I_B$. By KVL:

$$
V_B^{\rm th} - I_B\,R_{th} - V_{BE} - I_E\,R_E = 0.
$$

But $I_E \approx I_C + I_B \approx (\beta+1)I_B$. So:

$$
12.19 - I_B\cdot26.4k - 0.7 - (\beta+1)I_B\cdot1k = 0.
$$

Plug $\beta=120$:

$$
12.19 - 26.4k\,I_B - 0.7 -121\,I_B\cdot1k = 0
\quad\Longrightarrow\quad
11.49 - I_B(26.4k + 121k) = 0
$$

$$
I_B = \frac{11.49}{147.4\,\mathrm{k}\Omega}
     = 0.0780\,\mathrm{mA}
     = 78.0\,\mu\mathrm{A}.
$$

### 3. Compute $I_C$ and $I_E$

$$
I_C = \beta\,I_B = 120 \times 78.0\,\mu\mathrm{A}
      = 9.36\,\mathrm{mA},
$$

$$
I_E \approx (\beta+1)\,I_B = 121\times78.0\,\mu\mathrm{A}
    = 9.44\,\mathrm{mA}.
$$

### 4. Find voltages $V_E, V_C$

$$
V_E = I_E\,R_E = 9.44\rm\,mA\times1k = 9.44\,\mathrm{V}.
$$

$$
V_C = V_{CC} - I_C\,R_C = 18 - 9.36\times3.3
    = 18 - 30.9 \approx -12.9\,\mathrm{V}.
$$

A negative $V_C$ implies that, with these component values, the transistor is driven **into saturation** (since $V_C$ can’t go below 0 V in reality). Hence:

* **Q‑point:**
  $\displaystyle I_{CQ}\approx I_C=9.36\rm\,mA,\quad V_{CEQ}\approx V_C - V_E \approx 0 - 9.44 = -9.44\,V$
  (saturated—device not in linear region).

### 5. Stability factor $S$

For divider bias with emitter resistor $R_E$ and Thevenin $R_{th}$, the sensitivity to leakage is

$$
S = 1 + \frac{\beta\,R_E}{R_{th}}
  = 1 + \frac{120\times1\,\mathrm{k}\Omega}{26.4\,\mathrm{k}\Omega}
  = 1 + \frac{120}{26.4}
  \approx 1 + 4.545 \approx 5.545.
$$

---
---

## Q.4 Feedback Amplifiers

### Theory of Feedback

**Feedback** in an amplifier means taking a portion of the output signal and feeding it back to the input. There are two main types:

* **Negative feedback:** The fed‑back signal subtracts from the input.

  * **Effects:** Stabilizes gain, broadens bandwidth, reduces distortion and noise, increases input impedance (in voltage amplifiers), and lowers output impedance.
* **Positive feedback:** The fed‑back signal adds to the input.

  * **Effects:** Can produce regeneration (oscillations), hysteresis (as in Schmitt triggers), or bistability.

We describe a feedback loop by:

* $A$: the open‑loop gain of the amplifier block.
* $\beta$: the fraction of the output that is fed back.

The **closed‑loop gain** with feedback is

$$
A_{CL} = \frac{A}{1 \pm A\,\beta},
$$

where the “–” in the denominator is for **negative feedback**, and “+” for **positive feedback**.

---

### Q.4 (a) Draw the block diagram of a feedback amplifier and derive the expression for closed‑loop gain $A_{CL}$.

#### Block Diagram

```
    +              ┌─────────┐      ┌──────┐
Vin ──▶(+)─[ Σ ]──▶│ Amplifier │──▶│  β   │───┐
         │        └─────────┘      └──────┘   │
         ◀───(–)──────────────────────────────┘
                 feedback path
```

* **Σ (summer):** Takes the input $V_{\rm in}$ and subtracts (for negative feedback) or adds (for positive feedback) the feedback voltage $\beta\,V_{\rm out}$.
* **Amplifier block $A$:** Provides open‑loop gain $A$.
* **Feedback block $\beta$:** Feeds back a fraction $\beta$ of the output.

#### Derivation of Closed‑Loop Gain

1. Let the error signal at the summer be

   $$
     V_e = V_{\rm in} - \beta\,V_{\rm out}.
   $$
2. The amplifier output is

   $$
     V_{\rm out} = A\,V_e = A\bigl(V_{\rm in} - \beta\,V_{\rm out}\bigr).
   $$
3. Solve for the ratio $V_{\rm out}/V_{\rm in}$:

   $$
     V_{\rm out} = A\,V_{\rm in} - A\,\beta\,V_{\rm out}
     \quad\Longrightarrow\quad
     V_{\rm out}\bigl(1 + A\,\beta\bigr)
     = A\,V_{\rm in}.
   $$
4. Hence the **closed‑loop gain** is

   $$
     \boxed{A_{CL} = \frac{V_{\rm out}}{V_{\rm in}}
       = \frac{A}{1 + A\,\beta}\quad
       (\text{negative feedback}).}
   $$

---

### Q.4 (b) Give two circuit examples: one using negative feedback and one using positive feedback. State the purpose of each.

#### (i) Negative‑Feedback Example: Non‑Inverting Op‑Amp

**Circuit:**

```
        R1
  ┌─────┴─────┐
  │           │
  │      ┌─────────┐
Vin┤──▶ +│  Op‑Amp  │──▶ Vout
     └───│–         │
         └─────────┘
            │  │
            R2 │
            │  │
            └──┘
             ↓
            GND
```

* **Connections:**

  * Input goes to non‑inverting (+) input.
  * A resistor divider $R_1$–$R_2$ from output back to inverting (–) input provides feedback.
* **Gain:**

  $$
    A_{CL} = 1 + \frac{R_1}{R_2}.
  $$
* **Purpose of negative feedback:**

  * **Stabilizes gain** to the precise ratio $1 + R_1/R_2$ independent of the op‑amp’s open‑loop gain.
  * **Improves linearity** and reduces distortion.
  * **Extends bandwidth** (gain–bandwidth trade‑off).
  * **Increases input impedance** (ideal op‑amp has infinite input impedance).

---

#### (ii) Positive‑Feedback Example: Schmitt Trigger

**Circuit:**

```
         R1
  ┌──────┴──────┐
  │             │
  │   ┌──────────┐
Vin ─▶│  Op‑Amp   │──▶ Vout
     └─│+        │
       │         │
       └─────────┘
           │ │
           └─┘  
           Rf  
           │    
          Vin (also fed back)
```

* **Connections:**

  * Input and feedback both go to the non‑inverting (+) input.
  * The inverting (–) input is tied to a reference (e.g.\ ground).
* **Behavior:**

  * When $V_{\rm in}$ crosses a threshold, the output swings to the rail, reinforcing that state until the input crosses the opposite threshold.
* **Purpose of positive feedback:**

  * **Hysteresis:** Creates two distinct switching thresholds (upper and lower), providing noise immunity.
  * **Bistable operation:** Output stays in one of two stable states until input crosses a threshold.
  * **Oscillator building block:** With additional frequency‑selective networks (e.g.\ RC), positive feedback can sustain oscillations.

---
---

## Q.5 (a) Full‑Wave Bridge Rectifier

### Theory

A full‑wave bridge rectifier converts an AC input into a pulsating DC output using four diodes arranged in a bridge. Unlike a half‑wave rectifier, it utilizes both halves of the AC cycle, doubling the output frequency of the ripple and improving transformer utilization.

#### Circuit Diagram

```
    ~ Vin ~
      │   │
     D1   D2
      ↓   ↓
     +───┬───+ Vout
     │       │
    D3      D4
     ↑       ↑
      └─┬───┘
        │
       GND
```

* **D1, D2, D3, D4:** Four diodes forming the bridge.
* **Load $R_L$:** Connected across the bridge output.

### Operation

* **Positive Half‑Cycle (Vin positive at top terminal):**

  * Current flows through D1 → load $R_L$ → D4 → back to source.
  * D2 and D3 are reverse‑biased and do not conduct.
  * Load sees a positive voltage equal to $|V_{\rm in}|$.

* **Negative Half‑Cycle (Vin negative at top terminal):**

  * Current flows through D3 → load $R_L$ → D2 → back to source.
  * D1 and D4 are reverse‑biased.
  * Load again sees a positive voltage.

Hence, every half‑cycle produces a positive pulse across $R_L$.

### Waveform

```
Vin:      ~~~~~~       ~~~~~~
          /    \     /    \  
         /      \   /      \ 

Vout:    /\  /\       /\  /\
         /  \/  \     /  \/  \
```

* Peaks occur at the AC peak minus two diode drops.
* Ripple frequency is twice the AC supply frequency.

### Ripple Factor

Ripple factor $r$ quantifies the AC content in the DC output:

$$
r = \frac{V_{\rm rms\,(ripple)}}{V_{\rm DC}}.
$$

For a full‑wave rectifier without filter:

* The DC (average) output is

  $$
    V_{\rm DC} = \frac{2V_m}{\pi},
  $$

  where $V_m$ is the peak of the input sine.

* The rms value of the ripple component is

  $$
    V_{\rm rms\,(ripple)} = \sqrt{V_{\rm rms}^2 - V_{\rm DC}^2}
    = \sqrt{\frac{V_m^2}{2} - \Bigl(\frac{2V_m}{\pi}\Bigr)^2}.
  $$

Carrying out the algebra:

$$
r 
= \frac{\sqrt{\frac{V_m^2}{2} - \frac{4V_m^2}{\pi^2}}}
       {\frac{2V_m}{\pi}}
= \frac{V_m\sqrt{\frac{1}{2} - \frac{4}{\pi^2}}}{\frac{2V_m}{\pi}}
= \frac{\pi}{2}\sqrt{\frac{1}{2} - \frac{4}{\pi^2}}
= \frac{\pi}{2\sqrt{2}} - 1 
\approx 0.482.
$$

So the ripple factor for an unfiltered full‑wave bridge is approximately **0.482**.

---

## Q.5 (b) Difference Between Zener and Avalanche Breakdown

### Theory of Breakdown Mechanisms

A pn‑junction diode subjected to reverse bias will undergo breakdown when the applied voltage exceeds a critical value. Two primary mechanisms exist:

1. **Zener Breakdown (Quantum Tunneling)**

   * Occurs at relatively low breakdown voltages (typically < 5 V).
   * A very strong electric field across the depletion region allows valence‑band electrons to tunnel directly into the conduction band.
   * Sharp knee in the I–V curve; voltage remains nearly constant over a wide current range.
   * Used intentionally in Zener diodes for voltage reference and regulation.

2. **Avalanche Breakdown (Carrier Multiplication)**

   * Dominant at higher reverse voltages (> 5 V).
   * Carriers accelerated by the field gain enough energy to impact‑ionize lattice atoms, creating secondary electron‑hole pairs.
   * Results in a chain‐reaction (avalanche) multiplication.
   * Knee is less sharp; breakdown voltage depends on temperature and doping.

### Key Differences

| Feature                     | Zener Breakdown                     | Avalanche Breakdown                 |
| --------------------------- | ----------------------------------- | ----------------------------------- |
| **Voltage range**           | Low (≈2–5 V)                        | Higher (>,5 V)                      |
| **Mechanism**               | Quantum tunneling                   | Impact ionization                   |
| **I–V characteristic**      | Sharp knee, tight regulation        | Gradual knee, softer regulation     |
| **Temperature coefficient** | Negative (voltage decreases with T) | Positive (voltage increases with T) |
| **Typical use**             | Voltage reference/regulator         | High‑voltage protection             |

---
---

## Q.6 (a) Instrumentation Amplifier

### Theory

An **instrumentation amplifier** is a specialized differential amplifier designed for precise, low‑noise measurement of small differential signals in the presence of large common‑mode voltages. Its key features are:

1. **High input impedance** on both inputs, minimizing loading of the source.
2. **High common‑mode rejection ratio (CMRR)**, rejecting noise and interference equally present on both inputs.
3. **Easily adjustable gain** by a single resistor.

The most common topology uses **three op‑amps**:

* Two input buffer amplifiers (each configured as non‑inverting amplifiers) to provide high input impedance.
* A third differential amplifier stage that subtracts the two buffered signals and scales the result.

### Circuit & Derivation

```
   V1 ──▶┐        ┌─────────────┐        ┌───────────┐
         │        │  Buffer A   │        │           │
         └─ Rg ──▶│ (+)       (+)│─►─┐   │           │
   V2 ──▶┐        │ (–)       (–)│   │   │           │
         │        └─────────────┘   │   │           │
         │                          │   │ Differential
         │        ┌─────────────┐   │   │ Amplifier │─► Vout
         └─ Rg ──▶│  Buffer B   │◀──┘   │           │
                 │ (+)       (+)│       │           │
                 │ (–)       (–)│       │           │
                 └─────────────┘       └───────────┘
```

* **Buffers A & B:** Non‑inverting gain stages, each with gain

  $$
    G_1 = 1 + \frac{2R_1}{R_G},
  $$

  where $R_G$ is the single gain‑setting resistor between their inverting inputs, and $R_1$ is each feedback resistor.

* **Differential stage:** A classic subtractor that yields

  $$
    V_{\rm out} = G_1\,\bigl(V_2 - V_1\bigr).
  $$

Thus the overall gain is

$$
\boxed{\,V_{\rm out}
= \Bigl(1 + \tfrac{2R_1}{R_G}\Bigr)\,(V_2 - V_1)\,.}
$$

### Advantages & Disadvantages

* **Advantages:**

  * Very high CMRR.
  * High input impedance.
  * Gain easily adjustable by one resistor.
* **Disadvantages:**

  * Uses three op‑amps (more cost, power).
  * Matching of resistors is critical for CMRR.
  * Bandwidth decreases as gain increases.

---

## Q.6 (b) N‑Channel MOSFET Operation

**Given:**

$$
\mu C_{\rm ox}\frac{W}{L} = 0.2\,\mathrm{mA}/\mathrm{V}^2,\quad
V_{DS} = 0.2\,\mathrm{V},\quad
V_{GS} = V_I = 0.7\,\mathrm{V},\quad
V_T = 0.7\,\mathrm{V}.
$$

### Theory

An n‑channel MOSFET operates in three possible regions:

1. **Cutoff (OFF):** $V_{GS} < V_T$. No channel formed, $I_D\approx0$.
2. **Triode (Linear):** $V_{GS} > V_T$ and $V_{DS} < V_{GS} - V_T$. Channel exists and acts like a voltage‑controlled resistor:

   $$
   I_D = \mu C_{\rm ox}\frac{W}{L}
   \Bigl[(V_{GS}-V_T)V_{DS} - \tfrac12 V_{DS}^2\Bigr].
   $$
3. **Saturation:** $V_{GS} > V_T$ and $V_{DS} \ge V_{GS} - V_T$. Current saturates at

   $$
   I_D = \tfrac12\,\mu C_{\rm ox}\frac{W}{L}\,(V_{GS}-V_T)^2.
   $$

### Determine Region

Compute $V_{GS} - V_T = 0.7 - 0.7 = 0$. Since $V_{GS} - V_T = 0$, the channel is right at threshold and effectively **no channel** is formed. Thus the device is in **cutoff**, not conducting.

### Drain Current

Because $V_{GS} \le V_T$,

$$
\boxed{I_D \approx 0\;\text{mA}.}
$$

No further calculation is needed—the transistor remains OFF.

---
---

## Q.7 (a) Compare JFET and BJT

### Theory of Device Operation

* A **JFET (Junction Field-Effect Transistor)** is a voltage-controlled device where a reverse-biased p–n junction at the gate controls the channel conductivity.
* A **BJT (Bipolar Junction Transistor)** is a current-controlled device where a small base current controls a larger collector–emitter current.

| Feature                   | JFET                                           | BJT                                                 |
| ------------------------- | ---------------------------------------------- | --------------------------------------------------- |
| **Control Mechanism**     | Gate–source voltage $V_{GS}$                   | Base current $I_B$                                  |
| **Input Impedance**       | Very high ($\sim$MΩ to GΩ)                     | Moderate ($\sim$kΩ)                                 |
| **Noise Performance**     | Lower noise for small signals                  | Higher noise due to base current shot noise         |
| **Linearity**             | Good within small signal range                 | Good if properly biased                             |
| **Temperature Stability** | Better thermal stability (less drift)          | Prone to thermal runaway without bias stabilization |
| **Gain**                  | Moderate transconductance $g_m$                | High current gain $\beta$                           |
| **Switching Speed**       | Moderate                                       | Fast                                                |
| **Power Dissipation**     | Lower dissipation in gate (no DC gate current) | More gate/base current leads to higher dissipation  |

* **Applications:**

  * JFETs in low-noise analog front ends (e.g., sensor amplifiers).
  * BJTs where high gain or high-speed switching is needed.

---

## Q.7 (b) What is meant by “faithful amplification”?

**Theory of Faithful Amplification**

“Faithful amplification” refers to an amplifier’s ability to reproduce the input waveform at the output **without distortion** of its shape, phase, or relative amplitude (aside from the intended gain). Key requirements:

1. **Linearity:** The device must operate in its linear region, so output is a linear function of input.
2. **Constant Gain:** The small-signal gain must be constant over the entire amplitude of the input signal.
3. **Adequate Bandwidth:** The amplifier’s bandwidth must exceed the highest frequency component of the input to avoid phase/frequency distortion.
4. **Sufficient Slew Rate:** Must handle rapid voltage changes without slew-induced distortion.
5. **No Clipping:** The output voltage swing must be within the supply rails plus headroom.

When these conditions are met, the output waveform is a **scaled** (and possibly phase-shifted by a constant) but otherwise **undistorted** replica of the input.

---
---

## Question 8

### (a) 741 Op‑Amp: Internal Structure, Pin‑Out, and Key Specifications

**Theory and Overview**
The 741 is one of the most widely used general‑purpose operational amplifiers. Its design dates back to the late 1960s but remains instructive for understanding classic op‑amp architecture.

#### Internal Block Diagram

```
          ┌────────────────────────────────────────────┐
  Offset  │                                            │  Offset
   Null   ▼            Input Differential              ▼   Null
     1   ┌───┐       Amplifier Stage (PNP pair)     ┌───┐   8
  In–   ─▶│   │──► Active‑Load Current Mirrors ─►──│   │─ VCC(+)
  (Pin 2) └───┘                                    └───┘ (Pin 7)
              │                                      │
              │        Gain Stage (NPN CE w/        │
              │         Miller Compensation)        │
              ▼                                      ▼
            ┌───┐                                  ┌───┐
  In+   ─▶│   │──► Push‑Pull Output Stage (Class AB)│   │─ Output
  (Pin 3) └───┘                                  └───┘ (Pin 6)
                                  │
                               VEE(–) (Pin 4)
```

* **Input Stage (PNP Differential Pair):** Converts the voltage difference between the inverting (–) and non‑inverting (+) inputs into a differential current.
* **Active‑Load Current Mirrors:** Transforms the differential current into a single‑ended current, improving gain.
* **Intermediate Gain Stage:** An NPN common‑emitter amplifier provides most of the voltage gain; a Miller capacitor $C_C$ between its collector and base ensures stability (dominant‑pole compensation).
* **Output Stage (Class AB):** Complimentary NPN/PNP emitter followers that can both source and sink current efficiently, driving loads.

#### Pin‑Out and Functions

```
           ┌───────┐
   Offset1 │1     8│ Offset2
   Inverting│2     7│ VCC(+)
 Non‑inv.   │3     6│ Output
   VEE(–)   │4     5│ NC
           └───────┘
```

| Pin | Name                | Function                                                        |
| --- | ------------------- | --------------------------------------------------------------- |
| 1   | Offset Null         | Connect a potentiometer (to Pins 1–5) to null DC offset voltage |
| 2   | Inverting Input     | (–) input                                                       |
| 3   | Non‑inverting Input | (+) input                                                       |
| 4   | $V_{EE}$            | Negative supply (–V<sub>CC</sub>)                               |
| 5   | NC                  | No connection                                                   |
| 6   | Output              | Amplifier output                                                |
| 7   | $V_{CC}$            | Positive supply (+V<sub>CC</sub>)                               |
| 8   | Offset Null         | Second offset adjust pin                                        |

#### Key Specifications

* **Open‑Loop Gain:** Typically \~200,000 (≈106 dB) at DC.
* **Bandwidth:** Unity‑gain bandwidth ≈1 MHz.
* **Slew Rate:** ≈0.5 V/µs.
* **Input Offset Voltage:** ≈1 mV max (can be trimmed via offset null).
* **Input Bias Current:** ≈80 nA.
* **Common‑Mode Range:** From $V_{EE}+2 V$ up to $V_{CC}-2 V$.

---

### (b) Clamping Circuit with D₁ (Zener) and D₂ (Standard Diode)

#### Circuit and Purpose

A clamping circuit limits the amplitude of an output waveform to protect downstream stages or shape signals. Here, D₁ is a Zener diode (reverse‑biased) and D₂ is a regular silicon diode (forward‑biased in the opposite direction).

```
             ┌─────────────┐
             │             │
        ┌───▶┴┬─[D₁ Zener]──▶ + Clamped
        │      │  
      ┌─┴─┐    │  
Vin──▶│   │    │  
      │741│───┴┬─[D₂ diode]──▶ – Clamped  
      └───┘      │  
           VEE(–)│  
                 ▼  
                GND
```

* **Positive Swing:** When the amplifier output tries to exceed the Zener breakdown voltage $V_Z$ (≈4.78 V), D₁ conducts in reverse (Zener) mode. The output is clamped at roughly

  $$
    V_{O(+)} \approx V_Z + V_{D_{\rm on}}
    = 4.78\,\text{V} + 0.7\,\text{V} \approx 5.48\,\text{V}.
  $$

* **Negative Swing:** When the output goes below –0.7 V, D₂ forward‑conducts, clamping the negative peak at approximately

  $$
    V_{O(-)} \approx -V_{D_{\rm on}} \approx -0.7\,\text{V}.
  $$

#### Detailed Operation

1. **Below –0.7 V:**

   * D₂ forward‑biased → clamps at –0.7 V.
   * D₁ is off (reverse‑biased below its breakdown).

2. **Between –0.7 V and +4.78 V:**

   * Both diodes are off. The amplifier output follows the input linearly.

3. **Above ≈+5.48 V:**

   * D₁ enters Zener breakdown at 4.78 V, plus the forward drop of D₂ in series if used in some configurations. Here it clamps at ≈5.48 V.
   * D₂ remains reverse‑biased.

This configuration protects the load from excessive voltages and shapes the waveform to a defined window.

---
### Q.9 (a) Ideal Transformer Characteristics

An **ideal transformer** is a theoretical device that perfectly transfers electrical energy between two circuits via magnetic coupling, without any losses or parasitic effects. In practice, no transformer is truly ideal, but the ideal model provides a foundation for understanding real transformer behavior.

#### Key Characteristics of an Ideal Transformer

1. **Perfect Magnetic Coupling (Coupling Coefficient $k = 1$)**

   * All the magnetic flux generated in the primary winding links the secondary winding.
   * There is no leakage flux; hence, no leakage inductance.
   * Implication: 100% of the magnetic energy is transferred from primary to secondary.

2. **Zero Winding Resistance**

   * Both primary and secondary windings have no ohmic resistance.
   * **No copper (I²R) losses** occur in the windings.
   * Implication: No voltage drop or power loss due to winding resistance.

3. **Infinite Core Permeability ($\mu \to \infty$)**

   * The core requires no magnetomotive force (MMF) to establish the magnetic flux.
   * **No magnetizing current** is drawn at excitation (aside from that needed to magnetize winding inductance).
   * Implication: Core does not limit the flux; there is no magnetizing inductance drop.

4. **No Core Losses**

   * The core exhibits no hysteresis or eddy‑current losses.
   * **Zero iron losses** occur, even under alternating flux.
   * Implication: All energy goes into transferring flux; none is dissipated in the core.

5. **Infinite Bandwidth (No Parasitic Capacitance or Leakage Inductance)**

   * There is no inter-winding capacitance or stray inductance.
   * The transformer responds equally well to any frequency (from DC up to arbitrarily high frequencies).
   * Implication: Transformer action is purely instantaneous induction.

#### Ideal Transformer Equations

Let $N_1$ and $N_2$ be the number of turns on the primary and secondary windings, respectively. Then in the ideal model:

* **Voltage Transformation Ratio**

  $$
    \frac{V_1}{V_2} \;=\;\frac{N_1}{N_2}.
  $$
* **Current Transformation Ratio**

  $$
    \frac{I_1}{I_2} \;=\;\frac{N_2}{N_1}.
  $$
* **Impedance Reflection**
  A load impedance $Z_L$ on the secondary is “reflected” to the primary as

  $$
    Z_{\rm in} \;=\;\left(\frac{N_1}{N_2}\right)^{\!2}\,Z_L.
  $$

These relations arise directly from Faraday’s law of electromagnetic induction and Ampère’s circuital law, under the ideal assumptions above.

---

---

## Q.9 (b) Definitions of Key Electrical Quantities

In this part, we define five fundamental parameters used in AC and power analysis:

---

### (i) Root‑Mean‑Square (RMS) Value

**Definition:**
For a periodic current $i(t)$ (or voltage $v(t)$) with period $T$, the RMS value is the equivalent DC value that would deliver the same average power to a resistive load.

$$
\boxed{I_{\rm rms} 
= \sqrt{\frac{1}{T} \int_{0}^{T} [\,i(t)\,]^2 \,dt}}
\quad\text{or}\quad
\boxed{V_{\rm rms} 
= \sqrt{\frac{1}{T} \int_{0}^{T} [\,v(t)\,]^2 \,dt}}.
$$

* **Physical meaning:** If you pass $I_{\rm rms}$ through a resistor $R$, it dissipates the same heat as the time‑varying $i(t)$ does.
* **Example (sinusoid):** For $i(t)=I_m\sin(\omega t)$,

  $$
    I_{\rm rms} = \frac{I_m}{\sqrt{2}}.
  $$

---

### (ii) Form Factor

**Definition:**
The form factor is the ratio of the RMS value to the average (mean) value of the absolute waveform:

$$
\boxed{\text{Form Factor} 
= \frac{I_{\rm rms}}{I_{\rm avg}},}
\quad\text{where}\quad
I_{\rm avg}
= \frac{1}{T}\int_{0}^{T}|\,i(t)\,|\,dt.
$$

* **Interpretation:** Indicates how “peaky” the waveform is relative to its average.
* **Example (pure sine):**

  $$
  \text{Form Factor} 
  = \frac{I_m/\sqrt{2}}{2I_m/\pi}
  = \frac{\pi}{2\sqrt{2}}\approx1.11.
  $$

---

### (iii) Peak (Crest) Factor

**Definition:**
Also called the crest factor, it is the ratio of the waveform’s maximum (peak) value to its RMS value:

$$
\boxed{\text{Crest Factor} 
= \frac{I_{\rm peak}}{I_{\rm rms}} 
\quad\bigl(\text{or }V_{\rm peak}/V_{\rm rms}\bigr).}
$$

* **Interpretation:** Measures the extremeness of peaks relative to the effective value.
* **Example (pure sine):**

  $$
  \text{Crest Factor}
  = \frac{I_m}{I_m/\sqrt{2}} = \sqrt{2}\approx1.414.
  $$

---

### (iv) Complex Power

**Definition:**
Complex power $S$ in an AC circuit is the product of the RMS voltage and the complex conjugate of the RMS current:

$$
\boxed{S = P + jQ = V_{\rm rms}\,I_{\rm rms}^*,}
$$

where

* $P = V_{\rm rms} I_{\rm rms}\cos\phi$ is the **real (active) power**,

* $Q = V_{\rm rms} I_{\rm rms}\sin\phi$ is the **reactive power**,

* $\phi$ is the phase angle between voltage and current.

* **Units:** Volt‑amperes (VA) for $S$, watts (W) for $P$, volt‑ampere reactive (VAR) for $Q$.

* **Usage:** Captures both energy transfer and stored-and‑returned power in reactive elements.

---

### (v) Half‑Power (–3 dB) Frequency

**Definition:**
The half‑power frequency of a system (also called the –3 dB point) is the frequency at which the output power drops to half its maximum mid‑band value. Equivalently, the output amplitude falls to $1/\sqrt{2}$ of its low‑frequency (or peak) amplitude.

$$
\boxed{|H(f_{-3\,\text{dB}})| 
= \frac{1}{\sqrt{2}}\;|H_{\rm max}|,}
$$

where $H(f)$ is the system’s transfer function magnitude.

* **Interpretation:** Defines the bandwidth over which a filter, amplifier, or network maintains nearly constant gain.
* **Example:** A single‑pole RC low‑pass filter has

  $$
     f_{-3\rm dB} = \frac{1}{2\pi RC}.
  $$

---
---

## Q.9 (c) Two-Port Z-Parameters for Series-Connected Impedances

### Theory of Two-Port Networks

A **two-port network** is an electrical network with two pairs of terminals: an input port (port 1) and an output port (port 2). Z-parameters (impedance parameters) relate the port voltages $V_1, V_2$ to the port currents $I_1, I_2$ via:

$$
\begin{aligned}
V_1 &= Z_{11}\,I_1 + Z_{12}\,I_2,\\
V_2 &= Z_{21}\,I_1 + Z_{22}\,I_2.
\end{aligned}
$$

* $Z_{11}$: Input impedance with port 2 open ($I_2=0$).
* $Z_{22}$: Output impedance with port 1 open ($I_1=0$).
* $Z_{12}$ & $Z_{21}$: Transfer impedances (reverse and forward).

### Series-Connected Impedances $Z_a$ and $Z_b$

Consider two impedances $Z_a$ and $Z_b$ connected in series between port 1 and port 2:

```
Port 1───[ Za ]───[ Zb ]───Port 2
```

* Any current entering port 1 must flow through both $Z_a$ and $Z_b$ to exit port 2 (series connection).

#### Determination of Z-Parameters

1. **$Z_{11}$** (with $I_2=0$, i.e. port 2 open):

   * If no current leaves port 2, the series path is open at the far end, but to find $Z_{11}$ we apply a test current $I_1$ into port 1; that current flows through both $Z_a$ and $Z_b$.
   * The voltage at port 1 is

     $$
       V_1 = I_1\,(Z_a + Z_b).
     $$
   * Thus

     $$
       Z_{11} = Z_a + Z_b.
     $$

2. **$Z_{22}$** (with $I_1=0$, i.e. port 1 open):

   * Apply a test current $I_2$ into port 2; it flows backward through $Z_b$ then $Z_a$.
   * The voltage at port 2 (positive reference into the network) is

     $$
       V_2 = I_2\,(Z_a + Z_b).
     $$
   * Thus

     $$
       Z_{22} = Z_a + Z_b.
     $$

3. **$Z_{12}$** (with $I_1=0$):

   * Port 1 is open, apply $I_2$ into port 2; that current flows through both $Z_b$ (first) and $Z_a$.
   * The voltage at port 1 (with passive sign convention, positive leaving the network) is

     $$
       V_1 = I_2\,Z_b.
     $$
   * So

     $$
       Z_{12} = Z_b.
     $$

4. **$Z_{21}$** (with $I_2=0$):

   * Port 2 open, apply $I_1$ into port 1; that current flows through $Z_a$ then $Z_b$.
   * The voltage at port 2 (positive leaving) is

     $$
       V_2 = I_1\,Z_b.
     $$
   * Hence

     $$
       Z_{21} = Z_b.
     $$

Putting it all together, the Z-parameter matrix is

$$
\boxed{
\mathbf{Z} =
\begin{pmatrix}
Z_{11} & Z_{12}\\[6pt]
Z_{21} & Z_{22}
\end{pmatrix}
=
\begin{pmatrix}
Z_a + Z_b & Z_b\\[3pt]
Z_b & Z_a + Z_b
\end{pmatrix}.
}
$$

This matrix succinctly captures how series impedances couple port voltages and currents in a two-port description.

---
---

## Q 1 (a–j): Short Questions with Detailed Answers

**(a) Collector Current Calculation**
**Question:** For a base current $I_B = 10\,\mu\text{A}$ and $\beta_{dc} = 100$, what is $I_C$?
**Answer:** $I_C = \beta\,I_B = 100 \times 10\,\mu\text{A} = 1\,\text{mA}.$
**Explanation:** In forward‑active mode, the collector current is approximately $\beta$ times the base current.

---

**(b) Closed‑Loop Gain Variation**
**Question:** An amplifier has open‑loop gain $A = -1000$ and feedback factor $\beta = 0.1$. If $A$ changes by 20%, what is the percent change in closed‑loop gain $A_F$?
**Answer:** Approximately **0.2%**.
**Explanation:**

$$
A_F = \frac{A}{1 + A\beta},\quad A\beta = 100.
$$

A 20% change in $A$ produces

$$
\frac{\Delta A_F}{A_F}\approx\frac{0.20}{1 + 100}\approx0.002\;(0.2\%).
$$

Negative feedback divides gain variations by $1+A\beta$.

---

**(c) Valence Electrons of a Trivalent Impurity**
**Question:** A trivalent impurity atom has how many valence electrons?
**Answer:** **3**.
**Explanation:** “Trivalent” denotes three outer‑shell electrons available for bonding (e.g.\ Al in Si).

---

**(d) Primary Use of Zener Diodes**
**Question:** Zener diodes are used primarily as …
**Answer:** **Voltage regulators**.
**Explanation:** In reverse breakdown they clamp voltage nearly constant.

---

**(e) PIV of Half‑Wave Rectifier**
**Question:** Peak inverse voltage (PIV) rating of the diode in a half‑wave rectifier is …
**Answer:** $V_m$.
**Explanation:** The non‑conducting diode must withstand the full negative peak $V_m$.

---

**(f) Reverse‑Saturation Current Temperature Dependence**
**Question:** For every 10 °C rise, the reverse‑saturation current of a pn junction increases by …
**Answer:** **2×**.
**Explanation:** Silicon leakage roughly doubles for each 10 °C increase.

---

**(g) BJT Active Region**
**Question:** With BE forward‑biased and BC reverse‑biased, the BJT is in the … region.
**Answer:** **Active region**.
**Explanation:** Forward BE injects carriers; reverse BC collects them for amplification.

---

**(h) Phase Shift per RC Section**
**Question:** In an RC phase‑shift oscillator, each RC stage shifts phase by …
**Answer:** **60°**.
**Explanation:** Three identical RC networks each contribute 60° for a total 180°.

---

**(i) Exceeding PIV Rating**
**Question:** If PIV rating is exceeded, …
**Answer:** **The diode is destroyed**.
**Explanation:** Excess reverse voltage causes avalanche breakdown and damage.

---

**(j) J‑FET Drain Current at $V_{GS}=0$**
**Question:** For a J‑FET with $I_{DSS}=9\,\text{mA}$, $V_P=-3.5\,\text{V}$, what is $I_D$ at $V_{GS}=0$?
**Answer:** **9 mA**.
**Explanation:** At zero gate bias the J‑FET conducts its maximum drain current $I_{DSS}$.

---

## Q 2: Feedback and Op‑Amp Parameters

### (a) Definitions

1. **Common‑Mode Rejection Ratio (CMRR):**

   $$
     \mathrm{CMRR} = \frac{A_D}{A_{CM}},\quad
     \text{CMRR}_{\rm dB} = 20\log_{10}\!\bigl(A_D/A_{CM}\bigr).
   $$

   Measures how well an amplifier rejects signals common to both inputs.

2. **Gain–Bandwidth Product (GBW):**

   $$
     \mathrm{GBW} = A_{\rm OL}(0)\times f_p,\quad
     f_{CL}\approx \frac{\mathrm{GBW}}{A_{CL}}.
   $$

   Constant for a single‑pole op‑amp; trade‑off between gain and bandwidth.

3. **Slew Rate (SR):**

   $$
     \mathrm{SR} = \max\!\Bigl|\frac{dV_{\rm out}}{dt}\Bigr|.
   $$

   Maximum output voltage change rate (V/µs); must satisfy $SR \ge 2\pi f V_p$ for undistorted sine waves.

---

### (b) Barkhausen Criterion

An electronic loop oscillates at $\omega_0$ if:

1. **Magnitude:** $|A_{\rm OL}(j\omega_0)\beta| = 1.$
2. **Phase:** $\angle A_{\rm OL}(j\omega_0)\beta = 0^\circ$ (mod 360°).

---

## Q 3: Bias Stability Factors

### (a) Fixed‑Bias Circuit Stability Factor

* **Circuit:** Base resistor $R_B$ to $V_{CC}$, emitter grounded, include leakage $I_{CBO}$.
* **Collector current:**

  $$
    I_C = \beta\frac{V_{CC}-V_{BE}}{R_B} + (1+\beta)I_{CBO}.
  $$
* **Stability Factor:**

  $$
    S = \frac{\partial I_C}{\partial I_{CBO}} = 1+\beta.
  $$

### (b) Voltage‑Divider Bias Q‑Point & Stability

* **Given:** $R_1=39\,\mathrm{k}\Omega,\,R_2=82\,\mathrm{k}\Omega,\,R_C=3.3\,\mathrm{k}\Omega,\,R_E=1\,\mathrm{k}\Omega,\,V_{CC}=18\,\mathrm{V},\,\beta=120.$
* **Thevenin at base:**

  $$
    V_{th}=18\frac{82}{39+82}\approx12.19\,\mathrm{V},\quad
    R_{th} \approx 26.4\,\mathrm{k}\Omega.
  $$
* **Base current:**

  $$
    I_B=\frac{V_{th}-V_{BE}}{R_{th}+(\beta+1)R_E}
       =\frac{12.19-0.7}{26.4k+121k}\approx78\,\mu\mathrm{A}.
  $$
* **Collector current:** $I_C=\beta I_B\approx9.36\,\mathrm{mA}.$
* **Voltages:** $V_E=I_ER_E\approx9.44\,\mathrm{V},\;V_C=18-I_CR_C\approx-12.9\,\mathrm{V}.$
  → Transistor **saturates**.
* **Stability Factor:**

  $$
    S = 1 + \frac{\beta\,R_E}{R_{th}}
      \approx 1 + \frac{120\times1k}{26.4k}\approx5.55.
  $$

---

## Q 4: Feedback Amplifiers

### Theory of Feedback

* **Negative feedback:** Subtractive; stabilizes gain, widens bandwidth, reduces distortion, raises input impedance.
* **Positive feedback:** Additive; can create hysteresis or oscillations.

Closed‑loop gain (negative feedback):

$$
A_{CL} = \frac{A}{1 + A\beta}.
$$

### (a) Block Diagram & Derivation

```
Vin →(+)[Σ]─→│ A │─→ Vout
      ←─────[β]─────
```

$$
V_e = V_{\rm in} - \beta V_{\rm out},\quad
V_{\rm out} = A\,V_e
\;\Longrightarrow\;
A_{CL}=\frac{A}{1 + A\beta}.
$$

### (b) Examples

1. **Negative Feedback – Non‑Inverting Op‑Amp**

   * Gain $1 + R_1/R_2$.
   * Purpose: precise, stable gain; low distortion; high input impedance.

2. **Positive Feedback – Schmitt Trigger**

   * Hysteresis thresholds set by feedback network.
   * Purpose: noise‑immune digital switching; bistability; oscillator core.

---

## Q 5: Rectifiers & Breakdown

### (a) Full‑Wave Bridge Rectifier

* **Circuit:** Four diodes in bridge; both half‑cycles produce positive output.
* **Waveform:** Ripple frequency = 2× input frequency.
* **Ripple Factor (no filter):**

  $$
    r = \frac{I_{\rm rms(ripple)}}{I_{\rm DC}}
      = \frac{\pi}{2\sqrt2} - 1\approx0.482.
  $$

### (b) Zener vs. Avalanche Breakdown

| Feature            | Zener (≤5 V)                 | Avalanche (>5 V)        |
| ------------------ | ---------------------------- | ----------------------- |
| Mechanism          | Quantum tunneling            | Impact ionization       |
| I–V Characteristic | Sharp knee                   | Gradual knee            |
| Temp. Coefficient  | Negative                     | Positive                |
| Typical Use        | Voltage reference/regulation | High-voltage protection |

---

## Q 6: Instrumentation Amp & MOSFET

### (a) Instrumentation Amplifier

* **Topology:** Three op‑amps (two buffers + differential amplifier).
* **Gain:** $1 + \tfrac{2R_1}{R_G}$ applied to $(V_2 - V_1)$.
* **Features:** Very high CMRR, high input impedance, single‑resistor gain setting.

### (b) N‑Channel MOSFET

* **Given:** $\mu C_{\rm ox}W/L=0.2\,\mathrm{mA/V^2},\,V_{GS}=V_T=0.7\,\mathrm{V},\,V_{DS}=0.2\,\mathrm{V}.$
* **Region:** $V_{GS}-V_T=0$ → **Cutoff** (no channel).
* **Drain Current:** $I_D\approx0\,\mathrm{mA}.$

---

## Q 7: JFET vs. BJT & Faithful Amplification

### (a) Device Comparison

| Feature         | JFET (Voltage‑Controlled) | BJT (Current‑Controlled) |
| --------------- | ------------------------- | ------------------------ |
| Input Impedance | Very high (MΩ–GΩ)         | Moderate (kΩ)            |
| Noise           | Low                       | Higher                   |
| Gain            | Moderate                  | High (β)                 |
| Thermal Drift   | Lower                     | Higher                   |
| Switching Speed | Moderate                  | Fast                     |

### (b) Faithful Amplification

**Definition:** Output is an undistorted, scaled replica of input.
**Requirements:** Linearity, constant gain, adequate bandwidth, sufficient slew rate, no clipping.

---

## Q 8: 741 Op‑Amp & Clamping Circuit

### (a) 741 Op‑Amp

* **Stages:** PNP differential input → active‑load mirrors → NPN gain stage (Miller‑comp) → Class AB output.
* **Pin‑Out:**
  1: Offset null, 2: Inverting (–), 3: Non‑inverting (+), 4: VEE(–), 5: NC, 6: Output, 7: VCC(+), 8: Offset null.
* **Specs:** Open‑loop gain \~200 000, GBW ≈1 MHz, slew ≈0.5 V/µs, input bias ≈80 nA.

### (b) Clamping with D₁ (Zener) & D₂ (Diode)

* **Positive clamp:** D₁ Zener breaks at \~4.78 V → clamps at \~5.48 V.
* **Negative clamp:** D₂ forward conducts at \~0.7 V → clamps at –0.7 V.
* **Operation:** Protects/limits output between –0.7 V and +5.48 V.

---

## Q 9: Transformer & Two‑Port

### (a) Ideal Transformer Characteristics

1. Perfect coupling ($k=1$), no leakage.
2. Zero winding resistance, no copper losses.
3. Infinite core permeability, no magnetizing current.
4. No core (hysteresis/eddy) losses.
5. Infinite bandwidth, no parasitic elements.

$$
\frac{V_1}{V_2}=\frac{N_1}{N_2},\quad
\frac{I_1}{I_2}=\frac{N_2}{N_1},\quad
Z_{\rm in}=\bigl(N_1/N_2\bigr)^2Z_L.
$$

---

### (b) Electrical Quantity Definitions

1. **RMS Value:** $\displaystyle I_{\rm rms}=\sqrt{\frac1T\int_0^T i^2(t)\,dt}.$
2. **Form Factor:** $\displaystyle\frac{I_{\rm rms}}{I_{\rm avg}},\;I_{\rm avg}=\frac1T\int_0^T|i(t)|\,dt.$
3. **Crest Factor:** $\displaystyle\frac{I_{\rm peak}}{I_{\rm rms}}.$
4. **Complex Power:** $S=P+jQ=V_{\rm rms}I_{\rm rms}^*.$
5. **Half‑Power Frequency:** $|H(f_{-3dB})|=|H_{\max}|/\sqrt2.$

---

### (c) Two‑Port Z‑Parameters for Series Impedances

For series $Z_a$–$Z_b$ between ports:

$$
\begin{pmatrix}V_1\\V_2\end{pmatrix}
=
\begin{pmatrix}
Z_a + Z_b & Z_b\\
Z_b & Z_a + Z_b
\end{pmatrix}
\begin{pmatrix}I_1\\I_2\end{pmatrix}.
$$

* $Z_{11}=Z_{22}=Z_a+Z_b$,
* $Z_{12}=Z_{21}=Z_b$.

---


