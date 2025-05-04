###....Analog Exam....

---

## Q1. V–I Characteristic of a PN Junction Diode

**Answer:**

* **Forward Bias (V<sub>F</sub> > 0):** Above the threshold (≈0.7 V for Si), the current rises exponentially.
* **Reverse Bias (V<sub>R</sub> < 0):** Only a tiny leakage current flows until breakdown (at V<sub>BR</sub>), after which large reverse current conducts.

**Test Circuit Diagram:**

```
      + V                       A
     ┌─┴─┐   ┌───┐       ┌───┐  │
(+)──┤ + ├──▶│ D │───I──▶│ A │──┤  
     │   │   └───┘   │   └───┘  │
     │   │            │        │
     │   └─Voltmeter──┘        │
     │                        └┐
     └─────────────────────────┘
      (–)                       (–)
```

* **A** = Ammeter (series)
* **Voltmeter** across diode D

---

## Q2. V–I Characteristic of a Zener Diode
![alt text](image-1.png)

**Answer:**

* **Forward Bias:** Behaves like a normal diode (≈0.7 V drop).
* **Reverse Bias:** Remains off until V<sub>R</sub> reaches Zener voltage V<sub>Z</sub>, then clamps at V<sub>Z</sub> with substantial current.

**Test Circuit Diagram:**

```
      + V
     ┌─┴─┐           ┌───┐
(+)──┤ + ├─R─▶──────▶│ Z │──┐
     │   │           └───┘  │
     │   │            │     │
     │   └─Voltmeter──┘     │
     │                     └┐
     └──────────────────────┘
      (–)
```

* **R** = Series resistor to limit I<sub>Z</sub>

---

## Q3. Rectifier Circuits

### a) Half‑Wave Rectifier
![alt text](image-2.png)

**Description:** Passes only the positive half‑cycles.

```
      AC
     ~───┐    
         │
         ▶| D  
         │───▶─┐  
         │     │  
        [RL]   │  
         │     │  
     ────┴─────┴── (Ground)
```

### b) Full‑Wave Center‑Tap Rectifier
![alt text](image-3.png)

```
          ┌──────┐
    AC ~──┤      ├─▶|───┐ 
          │      │ D1   │
     ┌───┬┤ CT   ├─▶|───┘
     │   │└──────┘  D2  
     │   │        ┌─┐  
     │   │       [RL]  
     │   └────────┴─┘  
    (–)             (–)
```

* **CT** = Center tap of transformer secondary

### c) Bridge Rectifier

```
        D1      D2
    +──▶|───┐  ┌───▶|───+
    │       │  │        │
   ~│ AC    └──┘    AC  │~ 
    │       ┌──┐        │
    +───|◀──┘  └──|◀──+─▶
        D4      D3
           │
          [RL]
           │
          (–)
```

---

## Q4. Clamping Circuit (Positive Clamper)
---
![alt text](image-4.png)
---

**Function:** Shifts an AC waveform upward by charging C on peaks.

```
      AC 
     ~───┐
         │
         ▶| D
         │───┬──▶─ Output (shifted)
         │   │
        [C]  │
         │   │
     ────┴───┴── (Ground)
```

* **D** charges **C** during negative peaks, clamping the lowest point at 0 V.

---

## Q5. BJT Working Regions & Characteristics
---

![alt text](image-5.png)
---

**Regions:**

1. **Cut‑off:** V<sub>BE</sub> < 0.7 V, no IC.
2. **Active:** V<sub>BE</sub> ≈ 0.7 V, V<sub>CE</sub> > V<sub>CE(sat)</sub>; IC ≈ β IB.
3. **Saturation:** Both junctions forward‑biased; max IC limited by circuit.

**Output Characteristic (CE config):**

```
IC │       ________
   │      /       
   │     /  Active region (IC ∝ IB)
   │    /
   │   /      
   │__/ Saturation  
   └──────────────── VCE
```

**Common‑Emitter Test Circuit:**

```
    VCC
     │
    [RC]
     │
     C
      \
       │    (Collector)
       │
       B───▶ [RB] ──▶ Input
      /
     E
     │
    GND
```

---

## Q6. V–I Characteristics of CB vs. CE

---
![alt text](image-6.png)
---

| Config. | Input Terminals | Output Terminals | Voltage Gain | Current Gain |
| ------- | --------------- | ---------------- | ------------ | ------------ |
| **CB**  | E–B             | C–B              | High         | <1           |
| **CE**  | B–E             | C–E              | High         | High (≈β)    |

**Common‑Base Circuit:**

```
   VCC
    │
   [RC]
    │
    C
     \
      │
     ─┴─┐
   E─|   │─── Input (emitter)
     └──┘
    GND
```

**Common‑Emitter Circuit:**

```
   VCC
    │
   [RC]
    │
    C
     \
      │
      B─── [RB] ── Input
     /
    E
    │
   GND
```

---

## Q7. Ideal Diode as a Switch (Numerical Example)

---
![alt text](image-7.png)
---
* **Forward Bias:** Ideal diode ≡ closed switch (0 Ω).
* **Reverse Bias:** Ideal diode ≡ open switch (∞ Ω).

**Example Circuit:** 5 V source, 1 kΩ resistor, ideal diode in series.

```
  +5 V ──▶|───[1 kΩ]─── GND
         D   
```

* **Forward (ON):** I = 5 V/1 kΩ = 5 mA
* **Reverse (OFF):** I = 0 mA

---


---

![alt text](image.png)

## Q1. V–I Characteristic of a PN Junction Diode

**Detailed Theory:**

* **Diode Equation:**

  $$
    I = I_S\Bigl(e^{\frac{V_D}{nV_T}} - 1\Bigr)
  $$

  where
  $I_S$ is the reverse saturation current (∼10⁻¹² A for Si),
  $n$ the ideality factor (1–2),
  $V_T = kT/q\approx 25\,\text{mV}$ at room temperature.
* **Forward Region (V\_D > 0.7 V):** Exponential rise of current; knee around 0.6–0.7 V for Si.
* **Reverse Region (V\_D < 0):** Current saturates at –I\_S until avalanche breakdown (tens of volts) triggers large reverse current.



---

## Q2. V–I Characteristic of a Zener Diode

**Detailed Theory:**

* **Forward Bias:** Behaves identically to a PN diode with ≈0.7 V drop.
* **Reverse Bias:**

  * Below $V_Z$: only leakage ≈I\_S.
  * At $V_Z$ (e.g. 5.6 V): heavy avalanche/zener breakdown conducts.
  * Dynamic impedance $r_Z$ small, so voltage remains clamped near $V_Z$ over a wide current range.
* **Series Resistor:** Limits current to safe value: $I_Z = (V_\text{supply} - V_Z)/R$.



---

## Q3. Rectifier Circuits

### a) Half‑Wave Rectifier

* **Operation:** Only positive half‑cycles pass through; negative halves are blocked.
* **Output:** Pulsating DC with 50% ripple frequency.



### b) Full‑Wave Center‑Tap Rectifier

* **Operation:** Two diodes use alternate half‑cycles referencing center tap.
* **Output:** Pulsating DC at twice the line frequency, reduced ripple.



### c) Bridge Rectifier

* **Operation:** Four‑diode bridge flips both halves positive without needing center tap.
* **Output:** Same as full‑wave center‑tap but higher transformer utilization.



---

## Q4. Positive Clamping Circuit

**Detailed Theory:**

* **Clamping Action:**

  * During the negative peak, diode conducts, charging $C$ to the peak voltage.
  * On subsequent cycles, capacitor holds that charge, shifting the entire waveform upward.
* **Result:** The most negative point is clamped to 0 V, so the entire sine wave rides above ground by one peak amplitude.



---

## Q5. BJT Working Regions & Output Characteristics

**Detailed Theory:**

* **Cut‑off:** $V_{BE}<0.7$ V → no base injection → $I_C\approx 0$.
* **Active:** $V_{BE}\approx0.7$ V, $V_{CE}>V_{CE(sat)}$. Collector current $I_C=\beta I_B$.
* **Saturation:** Both junctions forward‑biased → limited collector current by external circuit → $V_{CE}\approx0.1$–0.2 V.

Output curves show $\,I_C$ rising and then leveling for different base currents $I_B$.



---

## Q6. V–I Characteristics: Common‑Base vs. Common‑Emitter

**Detailed Theory:**

* **Common‑Base (CB):**

  * **Input:** Emitter–base junction.
  * **Current Gain:** <1 (α ≈0.98).
  * **Output:** Collector current vs. $V_{CB}$; very flat in active region.
* **Common‑Emitter (CE):**

  * **Input:** Base–emitter junction.
  * **Current Gain:** High (β ≈50–200).
  * **Output:** Collector current vs. $V_{CE}$; steeper curves for each $I_B$.

Both plotted together highlight the difference in gain and knee behavior.



---

## Q7. Ideal Diode as a Switch

**Detailed Theory:**

* **Forward (ON) Mode:** Modeled as a short circuit (0 Ω); any forward voltage → finite current (e.g. 5 mA here).
* **Reverse (OFF) Mode:** Modeled as open circuit (∞ Ω); reverse voltage → zero current.
* **I–V Graph:** Vertical “ON” branch at $V_D=0$, horizontal “OFF” branch at $I=0$.



---

**All graphs above were generated programmatically to illustrate the exact behavior under idealized assumptions.**
