# Step-by-Step Solved Answers (One Question at a Time)

## Source 1: Artificial Intelligence (105501)

## Q.1 Choose the correct answer (Any seven) [2 x 7 = 14]

Below are all ten parts solved with correct option and concise justification.

1. Q1(a)
Question: In LISP, the function that returns the rest of the list after removing the first element is:
(i) car (ii) last (iii) cons (iv) cdr

Correct Option: (iv) cdr
Justification: cdr returns the tail of a list, that is, all elements except the first.

2. Q1(b)
Question: What is Artificial Intelligence?
(i) Putting your intelligence into computer
(ii) Programming with your own intelligence
(iii) Making a machine intelligent
(iv) Playing a game

Correct Option: (iii) Making a machine intelligent
Justification: AI is the science and engineering of creating systems that can perform tasks requiring human-like intelligence.

3. Q1(c)
Question: Which is the best way for game playing problems?
(i) Linear approach (ii) Heuristic approach (iii) Random approach (iv) An optimal approach

Correct Option: (ii) Heuristic approach
Justification: Game playing generally uses heuristic evaluation to guide search efficiently when complete exhaustive search is impractical.

4. Q1(d)
Question: Face Recognition system is based on which type of approach?
(i) Weak AI approach (ii) Applied AI approach (iii) Cognitive AI approach (iv) Strong AI approach

Correct Option: (ii) Applied AI approach
Justification: Face recognition is a practical implementation of AI in real-world tasks, so it is an applied AI system.

5. Q1(e)
Question: Which is not commonly used for AI programming?
(i) Prolog (ii) Java (iii) LISP (iv) Perl

Correct Option: (iv) Perl
Justification: Prolog and LISP are classical AI languages, and Java is widely used in AI applications; Perl is comparatively uncommon in AI.

6. Q1(f)
Question: What are not represented using propositional logic?
(i) Objects (ii) Relations (iii) Both objects and relations (iv) None

Correct Option: (iii) Both objects and relations
Justification: Propositional logic uses atomic true/false statements and does not explicitly represent objects and relations like first-order logic does.

7. Q1(g)
Question: Inference algorithm is complete only if:
(i) it can derive any sentence
(ii) it can derive any entailed sentence
(iii) it is truth preserving
(iv) it can derive any entailed sentence and it is truth preserving

Correct Option: (iv)
Justification: For ideal inference, completeness means deriving all entailed conclusions and soundness means truth preservation.

8. Q1(h)
Question: Which search strategy is called blind search?
(i) Uninformed search (ii) Informed search (iii) Simple reflex search (iv) All

Correct Option: (i) Uninformed search
Justification: Blind search is another name for uninformed search because it uses no heuristic domain knowledge.

9. Q1(i)
Question: Which is used for utility functions in game playing algorithm?
(i) Linear polynomial (ii) Weighted polynomial (iii) Polynomial (iv) Linear weighted polynomial

Correct Option: (iv) Linear weighted polynomial
Justification: Utility/evaluation functions are often modeled as weighted linear combinations of important board features.

10. Q1(j)
Question: Graph used to represent semantic network is:
(i) undirected graph (ii) directed graph (iii) DAG (iv) directed complete graph

Correct Option: (ii) directed graph
Justification: Semantic networks represent directional relations (is-a, part-of, has-a), so directed edges are used.

### Final exam note for Q1
In the exam, attempt any seven. The safest set from above is: (a), (b), (c), (e), (f), (h), (j).

---

Status: Step 1 complete. Ready for Step 2 (Source 1, Q2(a)) on your command.

---

## Q.2 (a) Define Artificial Intelligence (AI). Discuss the application areas of AI. [7 marks]

### INTRODUCTION AND DEFINITION

**Artificial Intelligence (AI)** is the branch of computer science and engineering that focuses on the design, development, and deployment of computational systems capable of performing tasks that conventionally require human intelligence. These tasks include visual perception, speech recognition, natural language understanding, decision making, learning from experience, and problem solving across diverse domains.

In a formal sense, AI refers to the science and engineering of making intelligent machines, particularly intelligent computer programs. It is the study of how to make computers do things at which people are better. From a rational-agent perspective (modern view), AI is the study of agents that perceive their environment through sensors and act upon that environment through actuators to maximize expected utility.

### CORE CAPABILITIES AND COMPETENCIES OF AI SYSTEMS

1. **Learning from Data and Experience**
   - Machine learning enables systems to improve performance without being explicitly programmed for every scenario.
   - Examples: supervised learning (predicting house prices from historical data), unsupervised learning (customer segmentation), reinforcement learning (game playing, robot control).

2. **Reasoning and Inference**
   - Logical reasoning using rules, probabilistic reasoning, and symbolic reasoning.
   - Making conclusions from facts and rules stored in knowledge bases.

3. **Problem Solving and Search**
   - Finding optimal or near-optimal solutions through search algorithms and heuristics.
   - Path planning, scheduling, and constraint satisfaction.

4. **Perception (Computer Vision and Speech Recognition)**
   - Visual perception: identifying objects, faces, scenes from images/video.
   - Speech recognition: converting audio to text and understanding intent.
   - Multimodal perception combining multiple data sources.

5. **Natural Language Processing**
   - Understanding written and spoken language.
   - Machine translation, sentiment analysis, text summarization, dialogue systems.

6. **Planning and Decision Making**
   - Autonomous planning of action sequences to achieve goals.
   - Decision making under uncertainty using probabilistic methods.

### APPLICATION AREAS OF ARTIFICIAL INTELLIGENCE

**1. Healthcare and Medicine**
- **Disease Diagnosis**: AI systems analyze medical images (X-rays, MRI, CT scans) and patient records to detect diseases like cancer, tuberculosis, and cardiac conditions earlier than human radiologists in some cases.
- **Drug Discovery**: Machine learning accelerates identification of drug candidates by predicting molecular properties and interactions.
- **Personalized Treatment**: AI recommends patient-specific treatment plans based on genetic and phenotype data.
- **Health Monitoring**: Wearable AI systems track vital signs and alert users to anomalies.
- **Real-world example**: IBM Watson for Oncology assists doctors in cancer treatment decisions.

**2. Finance and Banking**
- **Fraud Detection**: Anomaly detection identifies suspicious transactions in real-time using historical patterns.
- **Credit Scoring**: ML models assess creditworthiness and loan default risk.
- **Algorithmic Trading**: AI executes high-frequency trading based on market signals.
- **Customer Service**: Chatbots and virtual assistants handle routine queries, loan applications.
- **Real-world example**: Banks use AI to flag unusual spending patterns within minutes.

**3. Manufacturing and Industry 4.0**
- **Predictive Maintenance**: ML models predict equipment failures before they occur, reducing downtime.
- **Quality Control**: Computer vision inspects products for defects at manufacturing speed.
- **Process Optimization**: AI optimizes production parameters (temperature, pressure, flow rate) for efficiency.
- **Supply Chain**: Demand forecasting and inventory optimization.
- **Real-world example**: Predictive maintenance in factories reduces maintenance costs by 20-25%.

**4. Transportation and Autonomous Vehicles**
- **Self-Driving Cars**: Sensor fusion, computer vision, and path planning enable autonomous navigation.
- **Traffic Management**: AI optimizes traffic signal timing to reduce congestion.
- **Route Optimization**: Logistics companies use AI for efficient delivery route planning.
- **Real-world example**: Waymo, Tesla, and other companies deploy autonomous vehicle fleets.

**5. Education and E-Learning**
- **Intelligent Tutoring Systems**: Adaptive platforms that customize learning pace and content to individual students.
- **Automated Grading**: AI grades essays and subjective answers.
- **Plagiarism Detection**: Systems identify copied content across digital sources.
- **Student Performance Prediction**: Early identification of at-risk students.
- **Real-world example**: Carnegie Learning's MATHia adapts to student level in real-time.

**6. Agriculture**
- **Crop Disease Detection**: Computer vision identifies plant diseases from leaf images, enabling early intervention.
- **Yield Prediction**: ML models forecast harvest yields based on weather, soil, and historical data.
- **Precision Irrigation**: AI optimizes water usage based on soil moisture and weather forecasts.
- **Pest Management**: Predictive models warn farmers of pest outbreaks.
- **Real-world example**: Microsoft's AI for Earth project helps farmers in developing nations.

**7. E-Commerce and Customer Service**
- **Product Recommendations**: Collaborative filtering and content-based systems suggest products to customers.
- **Chatbots and Virtual Assistants**: 24/7 customer support for FAQ and order tracking.
- **Dynamic Pricing**: AI adjusts product prices based on demand, competition, and inventory.
- **Personalization**: Customized website experiences, email offers, and ads.
- **Real-world example**: Amazon's recommendation engine drives 35% of revenue.

**8. Government and Public Sector**
- **Smart Cities**: Traffic optimization, energy management, public safety using interconnected IoT sensors and AI.
- **Crime Prediction**: Historical crime data identifies high-risk areas and times.
- **Welfare Distribution**: Targeting social security and subsidies to eligible beneficiaries using data analysis.
- **Real-world example**: New York Police Department uses predictive policing algorithms.

**9. Legal and Compliance**
- **Contract Analysis**: ML extracts key terms and identifies risks in legal documents.
- **Regulatory Compliance**: AI monitors transactions and communications for compliance with regulations (AML, KYC).
- **Legal Research**: NLP systems search case law and statutes rapidly.

**10. Natural Language Applications**
- **Machine Translation**: Google Translate, Microsoft Translator use neural networks for multilingual translation.
- **Sentiment Analysis**: Understanding customer feedback from social media and reviews.
- **Content Summarization**: Automatic generation of summaries from long documents.
- **Dialogue Systems**: Conversational AI for customer service and personal assistants (Alexa, Siri, Google Assistant).

### IMPACT AND SOCIETAL BENEFITS

- **Increased Efficiency**: Automation of routine tasks frees human workers for complex, creative work.
- **Improved Accuracy**: AI often outperforms humans in narrow, well-defined tasks (image classification, Go).
- **Accessibility**: AI makes services accessible to people with disabilities (speech-to-text for deaf, image description for blind).
- **Cost Reduction**: Automating expensive processes (diagnostic imaging, legal document review) reduces costs.
- **Innovation**: AI enables new products and services (autonomous vehicles, personalized medicine) previously impossible.

### CONCLUSION

Artificial Intelligence has transitioned from theoretical research to practical deployment across industries. Its applications span healthcare, finance, manufacturing, transportation, education, agriculture, and many other domains, delivering measurable business and social value. While current AI systems are task-specific (narrow AI), their impact is already transformative. The key to responsible AI deployment lies in addressing ethical concerns, ensuring transparency, managing bias, and aligning AI objectives with human values. As research advances toward more general and robust AI, the scope of applications and societal impact will continue to expand.

---

Status: Step 2 complete. Ready for Step 3 (Source 1, Q2(b)) on your command.
