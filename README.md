# TRIT
**Dataset with Train Test Val split can be obtained here at**
https://drive.google.com/file/d/1IZn4uo5TZwZHgQElhy8Q8orkm6kByqkB/view?usp=sharing

**Annotated Dataset with labels and images for Yolo based models can be obtained here** 
https://drive.google.com/file/d/13RoKcmqP6mNHMYhNhOkihSn1CnlFrucO/view?usp=sharing

**Look at the following directory for details such as accuracy, precision, recall and confusion matrices**
https://github.com/Baalekshan/TRIT/tree/main/yolo_performance_metrics

## Final metrics (image-agnostic, box-level)

* Precision (B): 0.912
* Recall (B): 0.885
* F1-score (B): 0.899
* mAP@50: 0.922
* mAP@50–95: 0.555
On an unseen validation set, the YOLOv8 detector achieved 91.2% precision, 88.5% recall, and an F1-score of 89.9%, with mAP@50 = 92.2%.

# SEM Wafer Defect Detection using YOLOv8

![Python](https://img.shields.io/badge/Python-3.8%2B-blue)
![YOLOv8](https://img.shields.io/badge/Model-YOLOv8-green)
![Edge AI](https://img.shields.io/badge/Deployment-ONNX%20%7C%20NXP-orange)

This project implements an automated **Scanning Electron Microscope (SEM)** wafer defect detection system. By leveraging the **YOLOv8** architecture, the system accurately localizes and classifies semiconductor interconnect and surface defects from SEM-like imagery, with a specific focus on thin, low-contrast features.

## 📌 Problem Statement
Manual inspection of SEM wafer images is traditionally:
* **Time-consuming:** Requires significant human hours per wafer.
* **Subjective:** Prone to human error and inconsistency.
* **Difficult to scale:** Incompatible with high-volume semiconductor manufacturing.

This project addresses these challenges by automating the detection and classification process.

---

## 🛠 Synthetic SEM Dataset Generation
Real SEM wafer defect datasets are rarely public due to IP sensitivities. To bridge this gap, a custom synthetic data generation pipeline was developed.



### Structural Ground Truth
Instead of using purely generative AI, this project uses **backend VLSI GDS layout files** as the ground truth. These layouts were transformed into realistic SEM images using:
* **Classical Image Processing:** Grayscale conversion and Gaussian/Poisson noise injection.
* **Structural Modeling:** Edge roughness and **Line Edge Roughness (LER)** modeling.
* **Manual Defect Injection:** Realistic patterns (Opens, Shorts, Cracks) were injected using professional editing tools to ensure physical plausibility.
<p align="center">
  <img width="420" height="420" src="https://github.com/user-attachments/assets/b426abe2-2e90-46ee-891f-c947c00b251b" alt="SEM Sample 1" />
  <img width="420" height="420" src="https://github.com/user-attachments/assets/b9f76b47-61c6-49d5-8c92-9409871072f0" alt="SEM Sample 2" />
</p>

### Dataset Augmentation
The dataset was supplemented with limited public sources to improve class balance:
* **Zenodo**
* **DeepPCB**
* **Research Papers**
* **Diffusion Models & Gen-AI**

---

## 🔍 Defect Classes
The system detects **7 distinct classes** of semiconductor failures:

| Class ID | Defect Name | Description |
| :--- | :--- | :--- |
| **0** | Crack | Hairline or structural cracks in interconnects |
| **1** | LER | Excessive Line Edge Roughness |
| **2** | Open | Broken or disconnected metal lines |
| **3** | Other | Ambiguous or miscellaneous defects |
| **4** | Particle | Foreign particle contamination |
| **5** | Protrusion | Abnormal material protrusion from structures |
| **6** | Short | Electrical short between parallel interconnects |

---

## 🚀 Training Configuration

### Model Architecture
* **Model:** YOLOv8 Nano (`yolov8n.pt`)
* **Backbone:** Pretrained COCO weights
* **Model Size:** ~5.9 MB (Optimized for edge deployment)

### Training Details
* **Resolution:** 256 x 256 pixels
* **Optimizer:** AdamW
* **Epochs:** 100
* **Batch Size:** 16
* **Hardware:** NVIDIA RTX 5050

### Performance Metrics
* **Classification Accuracy:** ~90%
* **Detection Correctness:** ~92%
* **Analysis:** The model demonstrates strong class separability. Most false negatives stem from conservative objectness decisions rather than class confusion.

---

## Yolo Performance On Test Images
<img width="256" height="256" alt="03b0d4f3-b7307354-Cracks_0055" src="https://github.com/user-attachments/assets/2dfe18ee-4b6e-4a68-82ce-b7fe805305e6" />
<img width="256" height="256" alt="f56dc0ac-347d-4573-994d-c12913435603" src="https://github.com/user-attachments/assets/f56dc0ac-347d-4573-994d-c12913435603"/>

---
<img width="256" height="256" alt="fde8ac1d-cf0b3777-LER_0021" src="https://github.com/user-attachments/assets/9b5ecc9a-5a84-458c-80b1-541ce75b55c2" />
<img width="256" height="256" alt="fde8ac1d-cf0b3777-LER_0021" src="https://github.com/user-attachments/assets/bd31489f-bae3-46ec-969f-ecfcfcd16562" />

---

## Confusion Matrix
<img width="300" height="225" alt="confusion_matrix" src="https://github.com/user-attachments/assets/da9c589d-4093-49ec-a404-f54b5098b382" />

## Validation Predictions
<img width="345.6" height="345.6" alt="val_pred" src="https://github.com/user-attachments/assets/ce46d406-a1c8-420e-9060-29d59aaf1f75" />

## 📦 Deployment & Inference

### 1. Ultralytics-Based Inference
Used for validation and visualization:
* Directory-to-directory batch inference.
* Per-class colored bounding boxes.
* Adjustable confidence and IoU thresholds.

### 2. ONNX-Based Deployment
Exported to **ONNX** format for production environments:
* Custom post-processing logic.
* No Ultralytics dependency.
* Ideal for edge integration.

### 3. Edge Hardware
The system is designed for resource-constrained platforms:
* **Target Hardware:** NXP i.MX RT1170
* **Inference Framework:** NXP eIQ
* **Benefit:** Low-latency, real-time inspection.

---

## 📂 Project Structure
```text
dataset/
├── images/
│   ├── train/          # Synthetic SEM training images
│   └── val/            # Validation images
└── labels/
    ├── train/          # YOLO format .txt annotations
    └── val/            # Validation annotations
