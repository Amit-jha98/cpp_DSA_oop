
# 📚 Mathematics-III Differential Calculus
---

## 📌 Module 1: Successive Differentiation, Leibnitz’s Theorem, Limits, Continuity and Differentiability (Single Variable)

---

## 📖 1️⃣ Successive Differentiation

### 📌 Theory:

Successive differentiation means finding higher order derivatives of a function.
The first derivative gives the slope, the second gives concavity, and so on.

**Notation:**

* First derivative: $\frac{dy}{dx}$
* Second derivative: $\frac{d^2y}{dx^2}$
* $n$-th derivative: $\frac{d^n y}{dx^n}$

### 📋 Formula:

For any function $y = f(x)$

* $\frac{d^n}{dx^n} [e^{ax}] = a^n e^{ax}$
* $\frac{d^n}{dx^n} [\sin(ax)]$ and $\frac{d^n}{dx^n} [\cos(ax)]$ repeat after every 4 derivatives.

**Example:**

$$
\frac{d}{dx} \sin x = \cos x, \ \frac{d^2}{dx^2} \sin x = -\sin x, \ \text{and so on.}
$$

---

### 📝 How to Solve:

* Differentiate step by step till required order.
* Use known derivative formulas.

### 📌 Example:

Find $\frac{d^3}{dx^3} (x^3 e^{2x})$

**Solution:**
Use product rule and differentiate stepwise:

* 1st derivative:

$$
= 3x^2 e^{2x} + x^3 \times 2 e^{2x}
$$

Simplify and proceed for 2nd and 3rd.

---

## 📖 2️⃣ Leibnitz’s Theorem

### 📌 Theory:

Used to find the n-th derivative of a product of two functions.

### 📋 Formula:

$$
\frac{d^n}{dx^n}(uv) = \sum_{r=0}^{n} \binom{n}{r} \frac{d^{n-r}u}{dx^{n-r}} \cdot \frac{d^{r}v}{dx^r}
$$

**Where:**

* $\binom{n}{r}$ is combination.

---

### 📝 How to Solve:

* Identify $u$ and $v$.
* Find successive derivatives.
* Apply the formula.

### 📌 Example:

Find $\frac{d^2}{dx^2}(x^2 e^x)$

**Solution:**
$u = x^2, v = e^x$

Now using:

$$
\frac{d^2}{dx^2}(uv) = u''v + 2u'v' + u v''
$$

Compute and simplify.

---

## 📖 3️⃣ Limit of a Function

### 📌 Theory:

Limit describes the behavior of a function as it approaches a particular value.

### 📋 Formula:

$$
\lim_{x \to a} f(x)
$$

**Limit exists if:**

$$
\lim_{x \to a^-} f(x) = \lim_{x \to a^+} f(x)
$$

---

### 📝 How to Solve:

* Use direct substitution.
* If indeterminate (like 0/0), use factorization, L'Hopital's Rule, or rationalization.

### 📌 Example:

$$
\lim_{x \to 2} \frac{x^2-4}{x-2}
$$

**Solution:**
Factor numerator:

$$
= \frac{(x-2)(x+2)}{x-2} = x+2
$$

Now, substitute $x=2$
Answer = 4

---

## 📖 4️⃣ Continuity

### 📌 Theory:

A function is continuous at a point if:

* Left limit = Right limit = value at point.

### 📋 Formula:

Check:

$$
\lim_{x \to a^-} f(x) = \lim_{x \to a^+} f(x) = f(a)
$$

---

### 📝 How to Solve:

* Compute left and right hand limits.
* Check if equal to value at point.

### 📌 Example:

Is

$$
f(x) = \begin{cases}  
x^2, & x \leq 1 \\  
2x+1, & x>1  
\end{cases}
$$

continuous at $x=1$?

**Solution:**

* Left limit: $\lim_{x \to 1^-} x^2 = 1$
* Right limit: $\lim_{x \to 1^+} 2(1)+1 = 3$
* Since not equal ⇒ discontinuous.

---

## 📖 5️⃣ Differentiability

### 📌 Theory:

A function is differentiable at a point if its derivative exists at that point.

**Important:**
If differentiable ⇒ continuous
But continuous does not imply differentiable.

---

### 📋 Formula:

$$
f'(a) = \lim_{h \to 0} \frac{f(a+h)-f(a)}{h}
$$

---

### 📝 How to Solve:

* Check continuity first.
* Compute limit of derivative from left and right.
* If equal, it’s differentiable.

### 📌 Example:

Check differentiability of

$$
f(x) = |x|
$$

at $x=0$

**Solution:**
Left derivative: $-1$, Right derivative: $+1$
Since unequal ⇒ Not differentiable.

---

## ✅ Summary of Module 1 Formulas:

| Concept               | Formula                                                      |
| :-------------------- | :----------------------------------------------------------- |
| Successive derivative | $\frac{d^n}{dx^n} e^{ax} = a^n e^{ax}$                       |
| Leibnitz’s Theorem    | $\frac{d^n}{dx^n}(uv) = \sum \binom{n}{r} u^{(n-r)} v^{(r)}$ |
| Limit existence       | $\lim_{x \to a^-} = \lim_{x \to a^+}$                        |
| Continuity            | $\lim_{x \to a} f(x) = f(a)$                                 |
| Differentiability     | $f'(a) = \lim_{h \to 0} \frac{f(a+h)-f(a)}{h}$               |

---

## 📌 Module 2: Limits, Continuity, Differentiability (Several Variables), Partial Derivatives, Euler’s Theorem, Maxima-Minima, Lagrange Multipliers, Taylor/Maclaurin

---

## 📖 1️⃣ Limits, Continuity and Differentiability (Several Variables)

---

### 📌 Theory:

For a function of two variables $f(x, y)$,
**Limit exists at (a, b)** if:

$$
\lim_{(x, y) \to (a, b)} f(x, y)
$$

gives the same result along every path approaching (a, b).

**Continuity:**
Same as single variable:

* $\lim_{(x, y) \to (a, b)} f(x, y) = f(a, b)$

**Differentiability:**
A function is differentiable at a point if all its partial derivatives exist and are continuous at that point.

---

### 📋 Example:

Check limit:

$$
\lim_{(x, y) \to (0, 0)} \frac{x^2 y}{x^2 + y^2}
$$

**Solution:**

* Along $y=0$ → limit = 0
* Along $x=0$ → limit = 0
* Along $y = x$ →
  $\frac{x^3}{2x^2} = \frac{x}{2}$ → 0 as $x \to 0$

Since same along all paths → Limit exists and is 0.

---

## 📖 2️⃣ Partial Derivatives

---

### 📌 Theory:

It’s the derivative of a multivariable function w\.r.t. one variable while others are constant.

Notation:

$$
\frac{\partial f}{\partial x}, \frac{\partial f}{\partial y}
$$

**Second order partial derivatives:**

$$
\frac{\partial^2 f}{\partial x^2}, \frac{\partial^2 f}{\partial y^2}, \frac{\partial^2 f}{\partial x \partial y}
$$

---

### 📋 Example:

For $f(x, y) = x^2 y + 3y^2$

* $\frac{\partial f}{\partial x} = 2x y$
* $\frac{\partial f}{\partial y} = x^2 + 6y$

---

## 📖 3️⃣ Euler’s Theorem for Homogeneous Functions

---

### 📌 Theory:

If $f(x, y)$ is homogeneous of degree $n$
then:

$$
x \frac{\partial f}{\partial x} + y \frac{\partial f}{\partial y} = n f(x, y)
$$

---

### 📋 How to Check Homogeneity:

If replacing $x = \lambda x, y = \lambda y$ gives

$$
f(\lambda x, \lambda y) = \lambda^n f(x, y)
$$

then degree is $n$

---

### 📋 Example:

Check homogeneity and verify Euler’s theorem for
$f(x, y) = x^2 y + y^3$

**Solution:**

* Degree = 3
* $\frac{\partial f}{\partial x} = 2x y$
* $\frac{\partial f}{\partial y} = x^2 + 3 y^2$
  Now verify:

$$
x(2x y) + y(x^2 + 3 y^2) = 3 (x^2 y + y^3)
$$

✅ Verified

---

## 📖 4️⃣ Total Derivatives

---

### 📌 Theory:

If $z = f(x, y)$ where $x, y$ depend on $t$,
then:

$$
\frac{dz}{dt} = \frac{\partial z}{\partial x} \frac{dx}{dt} + \frac{\partial z}{\partial y} \frac{dy}{dt}
$$

---

### 📋 Example:

$z = x^2 y, x = t, y = t^2$

$$
\frac{dz}{dt} = 2x y \frac{dx}{dt} + x^2 \frac{dy}{dt}
$$

Substituting values, compute result.

---

## 📖 5️⃣ Maxima and Minima of Several Variables

---

### 📌 Theory:

To find maxima or minima of $f(x, y)$:

* Find partial derivatives, set them zero:

$$
\frac{\partial f}{\partial x} = 0, \frac{\partial f}{\partial y} = 0
$$

* Solve for critical points.

Use second derivative test:

$$
D = f_{xx} f_{yy} - (f_{xy})^2
$$

* If $D > 0$ and $f_{xx} > 0$ → Minima
* If $D > 0$ and $f_{xx} < 0$ → Maxima
* If $D < 0$ → Saddle point

---

### 📋 Example:

Find extreme values of $f(x, y) = x^2 + y^2 - 4x - 6y$

**Solution:**

* $f_x = 2x - 4 = 0$ → $x=2$
* $f_y = 2y - 6 = 0$ → $y=3$
* $D = (2)(2) - (0)^2 = 4 > 0$
* $f_{xx}=2 > 0$

→ Minima at (2,3)

---

## 📖 6️⃣ Lagrange Multipliers

---

### 📌 Theory:

Used to find maxima/minima of $f(x, y, z)$ under a constraint $g(x, y, z)=0$

**Condition:**

$$
\nabla f = \lambda \nabla g
$$

---

### 📋 Example:

Maximize $f(x, y) = xy$ subject to $x^2 + y^2 = 1$

**Solution:**

$$
f_x = \lambda g_x, f_y = \lambda g_y
$$

Solve for $x, y, \lambda$

---

## 📖 7️⃣ Taylor’s and Maclaurin’s Series (Multivariable)

---

### 📌 Theory:

Approximate $f(x, y)$ near point $(a, b)$

**Taylor’s formula:**

$$
f(x, y) = f(a, b) + (x-a) f_x + (y-b) f_y + \frac{1}{2} [(x-a)^2 f_{xx} + 2(x-a)(y-b) f_{xy} + (y-b)^2 f_{yy}]
$$

**Maclaurin’s series** is Taylor’s with $a = 0, b = 0$

---

### 📋 Example:

Find Taylor expansion of
$f(x, y) = x^2 + y^2$ about (0,0)

**Solution:**

* $f(0,0) = 0$
* $f_x = 2x, f_y = 2y$
* $f_{xx} = 2, f_{yy} = 2, f_{xy} = 0$

Substitute into formula.

---

## ✅ Module 2 Summary Formulas:

| Concept             | Formula                                                        |
| :------------------ | :------------------------------------------------------------- |
| Limit (2 variables) | Check limit along different paths                              |
| Partial Derivatives | $\frac{\partial f}{\partial x}, \frac{\partial f}{\partial y}$ |
| Euler’s Theorem     | $x f_x + y f_y = n f(x, y)$                                    |
| Total Derivative    | $\frac{dz}{dt} = f_x \frac{dx}{dt} + f_y \frac{dy}{dt}$        |
| Max-Min test        | $D = f_{xx} f_{yy} - (f_{xy})^2$                               |
| Lagrange Multiplier | $\nabla f = \lambda \nabla g$                                  |
| Taylor series       | Use expansion formula                                          |

---

## 📌 Module 3: Vector Calculus (Gradient, Divergence, Curl, Integrals, Theorems)

---

## 📖 1️⃣ Gradient of a Scalar Field

### 📌 Theory:

* A **scalar field** is a function that assigns a single value to every point in space (e.g. temperature at each point in a room).
* The **gradient** gives the direction and rate of fastest increase of a scalar field.
* It’s a vector quantity.

### 📋 Formula:

For scalar function $\phi(x, y, z)$

$$
\nabla \phi = \frac{\partial \phi}{\partial x} \hat{i} + \frac{\partial \phi}{\partial y} \hat{j} + \frac{\partial \phi}{\partial z} \hat{k}
$$

### 📌 Properties:

* Points in the direction of maximum increase of $\phi$
* Magnitude gives rate of increase.

---

### 📌 Example:

Find gradient of
$\phi = x^2 y + y z$

**Solution:**

$$
\nabla \phi = (2x y) \hat{i} + (x^2 + z) \hat{j} + (y) \hat{k}
$$

---

## 📖 2️⃣ Divergence of a Vector Field

### 📌 Theory:

* A **vector field** assigns a vector to each point (e.g. velocity of a fluid at different points).
* **Divergence** measures the net rate of flow (flux) out of a point.
* It’s a scalar quantity.

### 📋 Formula:

For vector field $\vec{F} = F_1 \hat{i} + F_2 \hat{j} + F_3 \hat{k}$

$$
\text{div} \, \vec{F} = \frac{\partial F_1}{\partial x} + \frac{\partial F_2}{\partial y} + \frac{\partial F_3}{\partial z}
$$

### 📌 Properties:

* If divergence = 0 → field is **solenoidal** (like incompressible fluid).

---

### 📌 Example:

Find divergence of
$\vec{F} = x^2 \hat{i} + y^2 \hat{j} + z^2 \hat{k}$

**Solution:**

$$
\text{div} \, \vec{F} = 2x + 2y + 2z
$$

---

## 📖 3️⃣ Curl of a Vector Field

### 📌 Theory:

* **Curl** measures the tendency of a vector field to rotate around a point.
* It’s a vector quantity.

### 📋 Formula:

$$
\text{curl} \, \vec{F} = \nabla \times \vec{F}
$$

Using determinant:

$$
= \begin{vmatrix}
\hat{i} & \hat{j} & \hat{k} \\
\frac{\partial}{\partial x} & \frac{\partial}{\partial y} & \frac{\partial}{\partial z} \\
F_1 & F_2 & F_3
\end{vmatrix}
$$

### 📌 Properties:

* If curl = 0 → field is **irrotational**.

---

### 📌 Example:

Find curl of
$\vec{F} = y z \hat{i} + z x \hat{j} + x y \hat{k}$

**Solution:**
Use determinant and expand.

---

## 📖 4️⃣ Directional Derivative

### 📌 Theory:

* Measures the rate of change of a scalar field in a given direction.
* Maximum value occurs along the direction of the gradient.

### 📋 Formula:

$$
D_{\hat{a}} \phi = \nabla \phi \cdot \hat{a}
$$

Where $\hat{a}$ is a unit vector.

---

### 📌 Example:

If $\phi = x^2 y$, find directional derivative at (1,1,0) in direction of $2\hat{i} + 2\hat{j} + \hat{k}$

**Solution:**

* Find gradient at (1,1,0)
* Normalize direction vector
* Take dot product.

---

## 📖 5️⃣ Line, Surface and Volume Integrals

### 📌 Theory:

**Line Integral:**
Integration of a vector function along a curve.

$$
\int_C \vec{F} \cdot d\vec{r}
$$

**Surface Integral:**
Integration of vector field over a surface.

$$
\iint_S \vec{F} \cdot \hat{n} \, dS
$$

**Volume Integral:**
Integration of scalar field over volume.

$$
\iiint_V f(x, y, z) \, dV
$$

---

### 📌 Example:

Evaluate
$\int_C \vec{F} \cdot d\vec{r}$
for $\vec{F} = x \hat{i} + y \hat{j}$ along path from (0,0) to (1,1)

**Solution:**
Parametrize: $x=t, y=t$
Integrate from 0 to 1.

---

## 📖 6️⃣ Vector Identities

**Important Identities:**

* $\nabla \times (\nabla \phi) = 0$
* $\nabla \cdot (\nabla \times \vec{F}) = 0$
* $\nabla \cdot (A \times B) = B \cdot (\nabla \times A) - A \cdot (\nabla \times B)$

---

## 📖 7️⃣ Fundamental Vector Theorems

### 📌 Green’s Theorem (Plane)

Converts line integral to double integral:

$$
\oint_C (M dx + N dy) = \iint_R \left(\frac{\partial N}{\partial x} - \frac{\partial M}{\partial y}\right) dx dy
$$

---

### 📌 Stokes’ Theorem (Surface)

Relates surface integral of curl to line integral:

$$
\oint_C \vec{F} \cdot d\vec{r} = \iint_S (\nabla \times \vec{F}) \cdot \hat{n} \, dS
$$

---

### 📌 Gauss Divergence Theorem (Volume)

Relates volume integral of divergence to surface integral:

$$
\iiint_V (\nabla \cdot \vec{F}) \, dV = \iint_S \vec{F} \cdot \hat{n} \, dS
$$

---

## 📖 Summary of Module 3 Formulas:

| Concept                | Formula                                                                                                                                        |
| :--------------------- | :--------------------------------------------------------------------------------------------------------------------------------------------- |
| Gradient               | $\nabla \phi = \frac{\partial \phi}{\partial x} \hat{i} + \frac{\partial \phi}{\partial y} \hat{j} + \frac{\partial \phi}{\partial z} \hat{k}$ |
| Divergence             | $\nabla \cdot \vec{F} = \frac{\partial F_1}{\partial x} + \frac{\partial F_2}{\partial y} + \frac{\partial F_3}{\partial z}$                   |
| Curl                   | Determinant form                                                                                                                               |
| Directional Derivative | $D_{\hat{a}} \phi = \nabla \phi \cdot \hat{a}$                                                                                                 |
| Line Integral          | $\int_C \vec{F} \cdot d\vec{r}$                                                                                                                |
| Green’s Theorem        | Converts line integral to double integral                                                                                                      |
| Stokes’ Theorem        | Converts curl surface integral to line integral                                                                                                |
| Divergence Theorem     | Converts divergence volume integral to surface                                                                                                 |

---
## 📌 Module 4: First Order Ordinary Differential Equations

---

## 📖 What is a Differential Equation?

An equation involving derivatives of a function is called a **differential equation**.

**Order:** Highest derivative present.
**Degree:** Power of highest order derivative (if polynomial in derivatives).

---

## 📖 1️⃣ Exact Differential Equations

### 📌 Theory:

An equation of the form:

$$
M(x, y) dx + N(x, y) dy = 0
$$

is **exact** if:

$$
\frac{\partial M}{\partial y} = \frac{\partial N}{\partial x}
$$

---

### 📋 Method to Solve:

1. Check exactness.
2. Find a function $F(x, y)$ such that:

$$
\frac{\partial F}{\partial x} = M, \ \frac{\partial F}{\partial y} = N
$$

3. Integrate:

   * Integrate $M$ w\.r.t $x$
   * Add function of $y$
   * Differentiate w\.r.t $y$ and compare with $N$
4. Combine and equate to constant.

---

### 📌 Example:

$$
(2xy + y^2) dx + (x^2 + 2xy) dy = 0
$$

**Solution:**

* Check:
  $\frac{\partial M}{\partial y} = 2x + 2y$
  $\frac{\partial N}{\partial x} = 2x + 2y$ ✔️
* Integrate $M$ w\.r.t $x$

$$
F = x^2 y + x y^2
$$

* Final answer:

$$
F(x, y) = C
$$

---

## 📖 2️⃣ Linear Differential Equation

### 📌 Theory:

A first order linear DE is:

$$
\frac{dy}{dx} + P(x) y = Q(x)
$$

---

### 📋 Method to Solve:

1. Find Integrating Factor (IF):

$$
IF = e^{\int P(x) dx}
$$

2. Multiply both sides by IF.
3. Integrate:

$$
\text{LHS becomes:} \ \frac{d}{dx}[y \times IF]
$$

4. Integrate RHS and solve.

---

### 📌 Example:

$$
\frac{dy}{dx} + y = e^x
$$

**Solution:**

* IF = $e^{\int 1 dx} = e^x$
* Multiply both sides by $e^x$
* Integrate both sides.
* Final answer:

$$
y e^x = \int e^{2x} dx = \frac{e^{2x}}{2} + C
$$

---

## 📖 3️⃣ Bernoulli’s Equation

### 📌 Theory:

Of the form:

$$
\frac{dy}{dx} + P(x) y = Q(x) y^n
$$

---

### 📋 Method to Solve:

1. Divide by $y^n$
2. Substitute $z = y^{1-n}$
3. Differentiate and reduce to linear form.
4. Use linear method.

---

### 📌 Example:

$$
\frac{dy}{dx} + y = y^2 \sin x
$$

**Solution:**

* Divide by $y^2$
* Substitute $z = y^{-1}$
* Get linear in $z$
* Solve using IF.

---

## 📖 4️⃣ Euler’s (Cauchy-Euler) Equation

### 📌 Theory:

A first order Euler's equation:

$$
x \frac{dy}{dx} + a y = b
$$

---

### 📋 Method to Solve:

1. Divide by $x$

$$
\frac{dy}{dx} + \frac{a}{x} y = \frac{b}{x}
$$

2. Use integrating factor method as linear.

---

### 📌 Example:

$$
x \frac{dy}{dx} + 2y = x^2
$$

**Solution:**

* IF = $e^{\int \frac{2}{x} dx} = x^2$
* Multiply both sides.
* Integrate.

---

## 📖 5️⃣ Equations not of First Degree

### 📌 Types and Solving Methods:

* **Solvable for p:** (p = dy/dx)

  * Find expression for p.
  * Integrate.

* **Solvable for y:**

  * Rewrite in y = ...
  * Integrate both sides.

* **Solvable for x:**

  * Rewrite in x = ...
  * Integrate.

---

## 📖 6️⃣ Clairaut’s Equation

### 📌 Theory:

Form:

$$
y = p x + f(p)
$$

---

### 📋 Method to Solve:

1. Differentiate both sides:

$$
\frac{dy}{dx} = p + x \frac{dp}{dx} + f'(p) \frac{dp}{dx}
$$

2. Equating dy/dx = p
3. Solve for general and singular solution.

---

### 📌 Example:

$$
y = p x + p^2
$$

**Solution:**

* General solution:

  * Keep p as constant.
* Singular solution:

  * Eliminate p using:

  $$
  \frac{dy}{dx} = p
  $$

  and

  $$
  \frac{dy}{dx} = p + (x + 2p) \frac{dp}{dx}
  $$

---

## 📖 Module 4 Summary Formulas:

| Type                   | Formula                                                         |
| :--------------------- | :-------------------------------------------------------------- |
| Exact                  | $\frac{\partial M}{\partial y} = \frac{\partial N}{\partial x}$ |
| Linear                 | $IF = e^{\int P(x) dx}$                                         |
| Bernoulli              | $z = y^{1-n}$                                                   |
| Euler’s (Cauchy-Euler) | Convert to linear using integrating factor                      |
| Clairaut’s             | $y = p x + f(p)$                                                |

---

## 📌 Module 5: Ordinary Differential Equations of Higher Orders

---

## 📖 What are Higher Order ODEs?

A differential equation involving derivatives of order 2 or higher is called a **higher order differential equation**.

**Example:**

$$
\frac{d^2y}{dx^2} + P(x)\frac{dy}{dx} + Q(x)y = R(x)
$$

---

## 📖 1️⃣ Second Order Linear Differential Equations with Variable Coefficients

### 📌 Theory:

General form:

$$
\frac{d^2 y}{dx^2} + P(x) \frac{dy}{dx} + Q(x) y = R(x)
$$

**If P, Q are functions of x, it’s variable coefficient.**

---

### 📋 Method to Solve:

* If solvable, use integrating factor or reduction to first order.
* Sometimes solved using substitution like:

  * $\frac{dy}{dx} = v$
  * $\frac{d^2 y}{dx^2} = \frac{dv}{dx}$

---

### 📌 Example:

$$
x^2 \frac{d^2 y}{dx^2} - x \frac{dy}{dx} + y = 0
$$

This is a **Cauchy-Euler equation**, handled in the next part.

---

## 📖 2️⃣ Cauchy-Euler (Equidimensional) Equation

### 📌 Theory:

Form:

$$
x^n \frac{d^n y}{dx^n} + \dots + a y = R(x)
$$

**It can be reduced to constant coefficient form using substitution:**

$$
x = e^t, \ y = v(t)
$$

or assume $y = x^m$

---

### 📋 Method to Solve:

* Assume $y = x^m$
* Substitute into equation.
* Get auxiliary equation in m.
* Solve for m.
* Write general solution.

---

### 📌 Example:

$$
x^2 y'' - 4x y' + 6 y = 0
$$

**Solution:**

* Let $y = x^m$
* Substitute:

$$
m(m-1) - 4m + 6 = 0
$$

Solve quadratic in m.

---

## 📖 3️⃣ Method of Variation of Parameters

### 📌 Theory:

Used when complementary solution (C.F.) is known and particular integral (P.I.) is to be found for:

$$
y'' + P y' + Q y = R(x)
$$

---

### 📋 Method to Solve:

1. Find complementary function (C.F.) using auxiliary equation.
2. Let:

$$
y_p = u_1 y_1 + u_2 y_2
$$

where $y_1, y_2$ are independent solutions of homogeneous part.

3. Use formulas:

$$
u_1' = -\frac{y_2 R}{W}, \ u_2' = \frac{y_1 R}{W}
$$

Where W = Wronskian:

$$
W = y_1 y_2' - y_2 y_1'
$$

4. Integrate $u_1', u_2'$ to find u1, u2.

---

## 📖 4️⃣ Power Series Solution

### 📌 Theory:

When variable coefficients prevent direct solution.

Assume:

$$
y = \sum_{n=0}^{\infty} a_n (x-x_0)^n
$$

Substitute into differential equation.

---

### 📋 Method to Solve:

* Differentiate assumed series.
* Substitute into ODE.
* Equate like powers of x.
* Find recurrence relation.
* Compute coefficients.

---

## 📖 5️⃣ Special Functions

### 📌 5.1 Legendre’s Differential Equation:

$$
(1 - x^2) \frac{d^2 y}{dx^2} - 2x \frac{dy}{dx} + n(n+1) y = 0
$$

**Solution:**
Legendre polynomials $P_n(x)$

Properties:

* Orthogonal on $[-1,1]$
* Degree n polynomial

---

### 📌 5.2 Bessel’s Differential Equation:

$$
x^2 y'' + x y' + (x^2 - n^2) y = 0
$$

**Solution:**
Bessel functions $J_n(x)$

Properties:

* Oscillating functions
* Series form:

$$
J_n(x) = \sum_{m=0}^{\infty} \frac{(-1)^m}{m! \Gamma(m+n+1)} \left(\frac{x}{2}\right)^{2m+n}
$$

---

## 📖 Module 5 Summary Formulas:

| Type                    | Formula                                  |
| :---------------------- | :--------------------------------------- |
| 2nd Order Linear        | Standard form, use auxiliary equation    |
| Cauchy-Euler            | Assume $y = x^m$                         |
| Variation of Parameters | $u_1', u_2'$ formulas                    |
| Power Series            | Assume series, substitute, equate powers |
| Legendre Equation       | Given form                               |
| Bessel Equation         | Given form and series                    |

---

## 📌 Example (Cauchy-Euler):

Solve:

$$
x^2 y'' - 3x y' + 4y = 0
$$

**Solution:**

* Assume $y = x^m$
* Substitute:

$$
m(m-1) - 3m + 4 = 0
$$

$$
m^2 - 4m + 4 = 0 \rightarrow (m-2)^2=0
$$

Double root → 2

General solution:

$$
y = C_1 x^2 + C_2 x^2 \ln x
$$

---

## 📌 Module 6: First Order Partial Differential Equations

---

## 📖 What is a Partial Differential Equation (PDE)?

A differential equation involving **partial derivatives** of a function of more than one independent variable.

**Order:** Highest order derivative involved
**Degree:** Power of highest order derivative if equation is polynomial in derivatives

**Example:**

$$
\frac{\partial z}{\partial x} + \frac{\partial z}{\partial y} = 0
$$

---

## 📖 1️⃣ Formation of PDEs

### 📌 Theory:

Formed by eliminating arbitrary constants or functions from a relation involving variables.

---

### 📋 Example:

Eliminate $a, b$ from

$$
z = a x + b y + c
$$

**Solution:**

* Differentiate w\.r.t. x:

$$
\frac{\partial z}{\partial x} = a
$$

* Differentiate w\.r.t. y:

$$
\frac{\partial z}{\partial y} = b
$$

* Now eliminate $a, b$
  Final PDE:

$$
\frac{\partial^2 z}{\partial x \partial y} = 0
$$

---

## 📖 2️⃣ Types of First Order PDEs

---

### 📖 2.1 Linear First Order PDE (Lagrange’s Equation)

**General form:**

$$
P \frac{\partial z}{\partial x} + Q \frac{\partial z}{\partial y} = R
$$

**Where P, Q, R are functions of x, y, z**

---

### 📋 Method to Solve:

Use **Lagrange’s auxiliary equations**

$$
\frac{dx}{P} = \frac{dy}{Q} = \frac{dz}{R}
$$

**Solve two ratios at a time**
Find two independent solutions $u(x, y, z) = c_1, v(x, y, z) = c_2$

Final solution:

$$
F(u, v) = 0
$$

---

### 📌 Example:

Solve

$$
\frac{\partial z}{\partial x} + \frac{\partial z}{\partial y} = 0
$$

**Solution:**

* P=1, Q=1, R=0
* Auxiliary eqns:

$$
\frac{dx}{1} = \frac{dy}{1} = \frac{dz}{0}
$$

* From $dx=dy \Rightarrow x-y = c_1$
* From $dz=0 \Rightarrow z=c_2$

Final solution:

$$
F(x-y, z) = 0
$$

or
$z = f(x-y)$

---

### 📖 2.2 Non-Linear PDE (Clairaut’s Type)

**Form:**

$$
z = p x + q y + f(p, q)
$$

Where
$p = \frac{\partial z}{\partial x}, q = \frac{\partial z}{\partial y}$

---

### 📋 Method to Solve:

* Differentiate both sides w\.r.t. x and y.
* Equating $\frac{\partial z}{\partial x} = p$
* Eliminate derivatives using consistency conditions.
* Get both **general** and **singular solution**

---

### 📌 Example:

Solve

$$
z = p x + q y + p q
$$

**Solution:**

* General solution: treat p, q as constants.
* Singular solution:
  Differentiate w\.r.t. p, q and eliminate.

---

## 📖 3️⃣ Standard Forms of First Order PDEs

* **Separable form:**
  $f(p, q) = 0$

* **Homogeneous:**
  When degree in p and q is same.

* **Clairaut’s type:**
  As above.

---

## 📖 4️⃣ Charpit’s Method (For Non-Linear First Order PDEs)

**Form:**

$$
F(x, y, z, p, q) = 0
$$

**Auxiliary equations:**

$$
\frac{dx}{F_p} = \frac{dy}{F_q} = \frac{dz}{p F_p + q F_q} = \frac{dp}{-F_x - p F_z} = \frac{dq}{-F_y - q F_z}
$$

Solve characteristic equations to get complete solution.

---

## 📖 Module 6 Summary Formulas:

| Type                         | Formula                                                                 |
| :--------------------------- | :---------------------------------------------------------------------- |
| Linear PDE                   | $P \frac{\partial z}{\partial x} + Q \frac{\partial z}{\partial y} = R$ |
| Lagrange Auxiliary Equations | $\frac{dx}{P} = \frac{dy}{Q} = \frac{dz}{R}$                            |
| Clairaut’s Type              | $z = p x + q y + f(p, q)$                                               |
| Charpit’s Method             | Set of auxiliary equations                                              |

---

## 📌 Example (Lagrange’s PDE):

Solve

$$
x \frac{\partial z}{\partial x} + y \frac{\partial z}{\partial y} = z
$$

**Solution:**

* P = x, Q = y, R = z
* Auxiliary:

$$
\frac{dx}{x} = \frac{dy}{y} = \frac{dz}{z}
$$

* Integrating:

$$
\ln x = \ln y + c_1, \ \ln y = \ln z + c_2
$$

* Combine:

$$
\frac{x}{y} = c_1, \frac{y}{z} = c_2
$$

Final solution:

$$
F\left(\frac{x}{y}, \frac{y}{z}\right) = 0
$$

---

---

Full Revision Summary**

---

## 📚 **Module 1: Successive Differentiation**

### 📖 Theory:

* Higher order derivatives: 2nd, 3rd… nth derivatives
* Successive differentiation means repeatedly differentiating a function

### 📋 Formula:

If $y = f(x)$

$$
\frac{d^n y}{dx^n}
$$

**Leibnitz’s Theorem:**

$$
\frac{d^n}{dx^n}(uv) = \sum_{r=0}^n \binom{n}{r} \frac{d^{n-r} u}{dx^{n-r}} \frac{d^r v}{dx^r}
$$

### 📝 Method:

* Differentiate as many times as asked
* Apply Leibnitz rule when product involved

---

## 📚 **Module 2: Multivariable Calculus**

### 📖 Theory:

* Functions of several variables
* Limit, continuity, differentiability like single-variable but must check all paths

**Partial Derivatives:**

$$
\frac{\partial f}{\partial x}, \frac{\partial f}{\partial y}
$$

**Euler’s Theorem (Homogeneous Function of Degree n):**

$$
x f_x + y f_y = n f(x, y)
$$

**Total Derivative:**

$$
\frac{dz}{dt} = f_x \frac{dx}{dt} + f_y \frac{dy}{dt}
$$

**Max-Min (2 variables):**

* Find critical points
* Check:

$$
D = f_{xx} f_{yy} - (f_{xy})^2
$$

* If D>0 and fxx>0 → Min
* If D>0 and fxx<0 → Max
* If D<0 → Saddle point

**Lagrange Multipliers:**

$$
\nabla f = \lambda \nabla g
$$

**Taylor’s Series (2 variables):**

$$
f(x, y) = f(a, b) + (x-a) f_x + (y-b) f_y + \frac{1}{2}[...]
$$

---

## 📚 **Module 3: Vector Calculus**

### 📖 Theory:

* **Gradient (of scalar φ):**

$$
\nabla \phi = \frac{\partial \phi}{\partial x} \hat{i} + ...
$$

* **Divergence (of vector F):**

$$
\nabla \cdot \vec{F} = \frac{\partial F_1}{\partial x} + ...
$$

* **Curl (of vector F):**

$$
\nabla \times \vec{F}
$$

(Use determinant)

* **Directional Derivative:**

$$
D_{\hat{a}} \phi = \nabla \phi \cdot \hat{a}
$$

**Integrals:**

* Line:
  $\int_C \vec{F} \cdot d\vec{r}$
* Surface:
  $\iint_S \vec{F} \cdot \hat{n} dS$
* Volume:
  $\iiint_V f(x, y, z) dV$

**Theorems:**

* Green’s:

$$
\oint_C (M dx + N dy) = \iint \left(\frac{\partial N}{\partial x} - \frac{\partial M}{\partial y}\right)
$$

* Stokes:

$$
\oint_C \vec{F} \cdot d\vec{r} = \iint_S (\nabla \times \vec{F}) \cdot \hat{n} dS
$$

* Gauss Divergence:

$$
\iiint (\nabla \cdot \vec{F}) dV = \iint \vec{F} \cdot \hat{n} dS
$$

---

## 📚 **Module 4: First Order Differential Equations**

### 📖 Theory:

* Involving only 1st derivative

**Exact:**

$$
\frac{\partial M}{\partial y} = \frac{\partial N}{\partial x}
$$

**Linear:**

$$
\frac{dy}{dx} + P y = Q
$$

Integrating factor (IF)

$$
e^{\int P dx}
$$

**Bernoulli:**

$$
\frac{dy}{dx} + P y = Q y^n
$$

Convert using substitution $z = y^{1-n}$

**Cauchy-Euler:**

$$
x \frac{dy}{dx} + a y = b
$$

Convert to linear form

**Clairaut’s:**

$$
y = p x + f(p)
$$

---

## 📚 **Module 5: Higher Order ODEs**

### 📖 Theory:

* 2nd or higher order derivatives

**Cauchy-Euler:**
Assume $y = x^m$

**Variation of Parameters:**
If CF known:

$$
y_p = u_1 y_1 + u_2 y_2
$$

Use:

$$
u_1' = -\frac{y_2 R}{W}, u_2' = \frac{y_1 R}{W}
$$

**Power Series:**
Assume:

$$
y = \sum a_n (x-x_0)^n
$$

**Legendre Equation:**

$$
(1-x^2) y'' - 2x y' + n(n+1) y = 0
$$

**Bessel’s Equation:**

$$
x^2 y'' + x y' + (x^2 - n^2) y = 0
$$

Solution: Bessel function $J_n(x)$

---

## 📚 **Module 6: First Order PDEs**

### 📖 Theory:

* Involves partial derivatives

**Lagrange’s Equation:**

$$
P \frac{\partial z}{\partial x} + Q \frac{\partial z}{\partial y} = R
$$

Use auxiliary:

$$
\frac{dx}{P} = \frac{dy}{Q} = \frac{dz}{R}
$$

**Clairaut’s PDE:**

$$
z = p x + q y + f(p, q)
$$

**Charpit’s Method (Nonlinear):**
Auxiliary system:

$$
\frac{dx}{F_p} = \frac{dy}{F_q} = \frac{dz}{pF_p + qF_q} = \frac{dp}{-F_x - p F_z} = \frac{dq}{-F_y - q F_z}
$$

---

---
***— Complete Theory Overview***
---
---

## 📖 **Module 1: Successive Differentiation**

Successive differentiation involves repeatedly differentiating a given function. The derivatives obtained after the first derivative are called higher order derivatives.
For example:

* The second derivative is the derivative of the first derivative.
* The third derivative is the derivative of the second derivative, and so on.

Successive differentiation is useful in physics and engineering to study the rate of change of velocity (acceleration), curvature of curves, and behavior of functions at certain points.

**Leibnitz’s Theorem** is an important result in successive differentiation when differentiating a product of two functions multiple times. It provides a formula to directly find the nth derivative of the product of two functions.

---

## 📖 **Module 2: Multivariable Calculus**

In many practical problems, functions depend on more than one independent variable, such as temperature distribution in a room (depends on x, y, and z).
Multivariable calculus extends the concepts of limits, continuity, and differentiability to functions of two or more variables.

**Partial derivatives** are derivatives of functions with respect to one variable while keeping others constant.

**Euler’s theorem** provides a relation between a homogeneous function and its partial derivatives, stating that for a homogeneous function of degree n, a particular weighted sum of its partial derivatives equals n times the function itself.

**Total derivative** accounts for how a function of multiple variables changes when each of its variables changes with respect to another variable (like time).

The **Maxima and Minima** of a multivariable function involve finding critical points where partial derivatives vanish and then using second derivative tests to classify those points as maxima, minima, or saddle points.

**Lagrange’s method of multipliers** is used to find the extreme values (maximum or minimum) of a function subject to one or more constraints. This is particularly useful in optimization problems in engineering.

**Taylor’s and Maclaurin’s theorems** extend Taylor’s series expansion to functions of several variables, allowing approximation of function values near a point using their derivatives.

---

## 📖 **Module 3: Vector Calculus**

Vector calculus deals with differentiation and integration of vector fields, which are functions that assign a vector to each point in space, such as the velocity of fluid at different locations.

The **Gradient** of a scalar field points in the direction of the maximum rate of increase of the function and its magnitude represents the rate of increase per unit distance.

The **Divergence** of a vector field measures the net rate at which a quantity leaves a given point (source strength). Positive divergence implies a source; negative implies a sink.

The **Curl** of a vector field measures its tendency to rotate around a point. A field with zero curl is called irrotational.

The **Directional derivative** gives the rate of change of a scalar field in a specific direction.

Vector calculus also involves integration:

* **Line integral** computes the work done by a force field along a path.
* **Surface integral** measures the flux of a vector field through a surface.
* **Volume integral** accumulates a quantity over a three-dimensional region.

**Green’s, Stokes’, and Gauss’s divergence theorems** are fundamental results connecting integrals over regions to integrals over their boundaries, widely applied in fluid mechanics and electromagnetism.

---

## 📖 **Module 4: First Order Ordinary Differential Equations**

A first order ordinary differential equation involves only the first derivative of the unknown function.

An **Exact differential equation** occurs when a function exists whose total derivative equals the given differential equation. This function is found by integrating the components of the differential equation.

A **Linear differential equation** has the unknown function and its first derivative appearing to the first power and no product of them. It can be solved using an integrating factor.

**Bernoulli’s differential equation** is a nonlinear equation that can be transformed into a linear form by a suitable substitution, typically used when the dependent variable appears with a power other than 1.

A **Cauchy-Euler equation** has variable coefficients and can be reduced to a constant coefficient equation by substituting the dependent variable as a power of the independent variable.

Certain types of equations are **solvable for the derivative, for x, or for y** directly by rearranging the equation.

**Clairaut’s equation** is a first order differential equation where the dependent variable is a linear function of the independent variable and its derivative. It often yields both a general solution (a family of straight lines) and a singular solution (an envelope to the family of lines).

---

## 📖 **Module 5: Ordinary Differential Equations of Higher Orders**

Higher order differential equations involve derivatives of second or higher orders.

The **Cauchy-Euler (Equidimensional) equation** has variable coefficients that are powers of the independent variable. It can be simplified by assuming a solution of the form of a power of the independent variable.

The **method of variation of parameters** is a technique to find the particular solution of a non-homogeneous differential equation when the complementary solution is known. It involves treating the constants in the complementary solution as functions to be determined.

The **power series method** involves assuming the solution as an infinite series and substituting it into the differential equation to find a recurrence relation for the coefficients.

**Legendre’s differential equation** and **Bessel’s differential equation** are two important second-order linear differential equations with variable coefficients that appear frequently in physics and engineering problems involving spherical or cylindrical symmetry. Their solutions are known as **Legendre polynomials** and **Bessel functions** respectively.

---

## 📖 **Module 6: First Order Partial Differential Equations**

A first order partial differential equation involves partial derivatives of an unknown function with respect to two or more independent variables.

**Formation of PDEs** involves eliminating arbitrary constants or functions from a given relation between variables.

**Linear first order PDEs** have the unknown function and its partial derivatives appearing linearly and can be solved using **Lagrange’s method of auxiliary equations**, which converts the PDE into a set of ordinary differential equations (called characteristic equations).

**Clairaut’s PDE** involves the unknown function as a linear function of its partial derivatives. Its general solution involves arbitrary constants, and it also has a singular solution obtained by differentiating with respect to these arbitrary constants.

**Non-linear PDEs** can be tackled using **Charpit’s method**, which constructs a set of auxiliary equations (characteristic equations) using partial derivatives of the original equation and then integrates them to find the complete solution.

---