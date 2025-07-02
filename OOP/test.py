import torch
import torch_directml
import tensorflow as tf
import time
import numpy as np
import matplotlib.pyplot as plt
from typing import Dict, List, Tuple
import gc

class UnifiedBenchmark:
    def __init__(self):
        # PyTorch setup
        self.pytorch_cpu_device = torch.device('cpu')
        self.pytorch_gpu_device = torch_directml.device()
        
        # TensorFlow setup
        self.tf_devices = tf.config.list_physical_devices()
        self.tf_gpu_devices = tf.config.list_physical_devices('GPU')
        
        # Enable GPU memory growth for TensorFlow
        if self.tf_gpu_devices:
            try:
                for gpu in self.tf_gpu_devices:
                    tf.config.experimental.set_memory_growth(gpu, True)
            except RuntimeError as e:
                print(f"GPU memory growth setting failed: {e}")
        
        self.results = {}
        
        print("=== PyTorch DirectML vs TensorFlow DirectML Benchmark ===")
        print(f"PyTorch CPU Device: {self.pytorch_cpu_device}")
        print(f"PyTorch GPU Device: {self.pytorch_gpu_device}")
        print(f"PyTorch DirectML Available: {torch_directml.is_available()}")
        
        print(f"TensorFlow Version: {tf.__version__}")
        print(f"TensorFlow GPU Devices: {len(self.tf_gpu_devices)}")
        print(f"TensorFlow Devices: {[device.name for device in self.tf_devices]}")
        
        print("-" * 70)

    def benchmark_operation(self, operation_name: str, pytorch_func, tensorflow_func, *args, **kwargs) -> Dict[str, float]:
        """Benchmark an operation on both PyTorch and TensorFlow with CPU and GPU"""
        results = {}
        
        # PyTorch GPU Benchmark
        try:
            # Warm up
            for _ in range(3):
                pytorch_func(*args, device=self.pytorch_gpu_device, **kwargs)
            
            start_time = time.time()
            result_pytorch_gpu = pytorch_func(*args, device=self.pytorch_gpu_device, **kwargs)
            pytorch_gpu_time = time.time() - start_time
            
            results['pytorch_gpu_time'] = pytorch_gpu_time
            
        except Exception as e:
            print(f"PyTorch GPU benchmark failed for {operation_name}: {e}")
            results['pytorch_gpu_time'] = float('inf')
        
        # PyTorch CPU Benchmark
        try:
            # Warm up
            for _ in range(3):
                pytorch_func(*args, device=self.pytorch_cpu_device, **kwargs)
            
            start_time = time.time()
            result_pytorch_cpu = pytorch_func(*args, device=self.pytorch_cpu_device, **kwargs)
            pytorch_cpu_time = time.time() - start_time
            
            results['pytorch_cpu_time'] = pytorch_cpu_time
            
        except Exception as e:
            print(f"PyTorch CPU benchmark failed for {operation_name}: {e}")
            results['pytorch_cpu_time'] = float('inf')
        
        # TensorFlow GPU Benchmark
        try:
            if self.tf_gpu_devices:
                with tf.device('/GPU:0'):
                    # Warm up
                    for _ in range(3):
                        tensorflow_func(*args, **kwargs)
                    
                    start_time = time.time()
                    result_tf_gpu = tensorflow_func(*args, **kwargs)
                    tf_gpu_time = time.time() - start_time
                    
                    results['tensorflow_gpu_time'] = tf_gpu_time
            else:
                results['tensorflow_gpu_time'] = float('inf')
                
        except Exception as e:
            print(f"TensorFlow GPU benchmark failed for {operation_name}: {e}")
            results['tensorflow_gpu_time'] = float('inf')
        
        # TensorFlow CPU Benchmark
        try:
            with tf.device('/CPU:0'):
                # Warm up
                for _ in range(3):
                    tensorflow_func(*args, **kwargs)
                
                start_time = time.time()
                result_tf_cpu = tensorflow_func(*args, **kwargs)
                tf_cpu_time = time.time() - start_time
                
                results['tensorflow_cpu_time'] = tf_cpu_time
                
        except Exception as e:
            print(f"TensorFlow CPU benchmark failed for {operation_name}: {e}")
            results['tensorflow_cpu_time'] = float('inf')
        
        # Calculate speedups
        if results['pytorch_cpu_time'] != float('inf') and results['pytorch_gpu_time'] != float('inf'):
            results['pytorch_speedup'] = results['pytorch_cpu_time'] / results['pytorch_gpu_time']
        else:
            results['pytorch_speedup'] = 0
            
        if results['tensorflow_cpu_time'] != float('inf') and results['tensorflow_gpu_time'] != float('inf'):
            results['tensorflow_speedup'] = results['tensorflow_cpu_time'] / results['tensorflow_gpu_time']
        else:
            results['tensorflow_speedup'] = 0
        
        # GPU vs GPU comparison
        if results['pytorch_gpu_time'] != float('inf') and results['tensorflow_gpu_time'] != float('inf'):
            results['gpu_comparison'] = results['tensorflow_gpu_time'] / results['pytorch_gpu_time']
        else:
            results['gpu_comparison'] = 0
        
        self.results[operation_name] = results
        return results

    # PyTorch operations
    def pytorch_matrix_multiplication(self, size1: Tuple[int, int], size2: Tuple[int, int], device: torch.device):
        """PyTorch matrix multiplication"""
        a = torch.randn(size1, device=device)
        b = torch.randn(size2, device=device)
        return torch.mm(a, b)

    def pytorch_convolution_2d(self, batch_size: int, channels: int, height: int, width: int, device: torch.device):
        """PyTorch 2D Convolution"""
        input_tensor = torch.randn(batch_size, channels, height, width, device=device)
        conv_layer = torch.nn.Conv2d(channels, 64, kernel_size=3, padding=1).to(device)
        return conv_layer(input_tensor)

    def pytorch_element_wise_operations(self, size: Tuple[int, ...], device: torch.device):
        """PyTorch element-wise operations"""
        a = torch.randn(size, device=device)
        b = torch.randn(size, device=device)
        
        result = torch.add(a, b)
        result = torch.mul(result, a)
        result = torch.sin(result)
        result = torch.exp(result)
        return result

    # TensorFlow operations
    def tensorflow_matrix_multiplication(self, size1: Tuple[int, int], size2: Tuple[int, int]):
        """TensorFlow matrix multiplication"""
        a = tf.random.normal(size1)
        b = tf.random.normal(size2)
        return tf.linalg.matmul(a, b)

    def tensorflow_convolution_2d(self, batch_size: int, channels: int, height: int, width: int):
        """TensorFlow 2D Convolution"""
        input_tensor = tf.random.normal([batch_size, height, width, channels])
        conv_layer = tf.keras.layers.Conv2D(64, 3, padding='same')
        return conv_layer(input_tensor)

    def tensorflow_element_wise_operations(self, size: Tuple[int, ...]):
        """TensorFlow element-wise operations"""
        a = tf.random.normal(size)
        b = tf.random.normal(size)
        
        result = tf.add(a, b)
        result = tf.multiply(result, a)
        result = tf.sin(result)
        result = tf.exp(result)
        return result

    def run_comprehensive_benchmark(self):
        """Run comprehensive benchmark suite comparing PyTorch and TensorFlow"""
        print("Starting Comprehensive PyTorch vs TensorFlow Benchmark...\n")
        
        # Test configurations
        test_configs = [
            ("Matrix Mult 512x512", 
             self.pytorch_matrix_multiplication, self.tensorflow_matrix_multiplication,
             (512, 512), (512, 512)),
            ("Matrix Mult 1024x1024", 
             self.pytorch_matrix_multiplication, self.tensorflow_matrix_multiplication,
             (1024, 1024), (1024, 1024)),
            ("Matrix Mult 2048x2048", 
             self.pytorch_matrix_multiplication, self.tensorflow_matrix_multiplication,
             (2048, 2048), (2048, 2048)),
            ("Conv2D (1,3,224,224)", 
             self.pytorch_convolution_2d, self.tensorflow_convolution_2d,
             1, 3, 224, 224),
            ("Conv2D (8,64,128,128)", 
             self.pytorch_convolution_2d, self.tensorflow_convolution_2d,
             8, 64, 128, 128),
            ("Element-wise (1000,1000)", 
             self.pytorch_element_wise_operations, self.tensorflow_element_wise_operations,
             (1000, 1000)),
            ("Element-wise (5000,5000)", 
             self.pytorch_element_wise_operations, self.tensorflow_element_wise_operations,
             (5000, 5000)),
        ]
        
        for config in test_configs:
            test_name = config[0]
            pytorch_func = config[1]
            tensorflow_func = config[2]
            test_args = config[3:]
            
            print(f"Running: {test_name}")
            try:
                results = self.benchmark_operation(test_name, pytorch_func, tensorflow_func, *test_args)
                self.print_results(test_name, results)
                
                # Clean up memory
                gc.collect()
                tf.keras.backend.clear_session()
                
            except Exception as e:
                print(f"Error in {test_name}: {e}")
            
            print("-" * 50)

    def run_enhanced_benchmark(self):
        """Run enhanced benchmark with multiple iterations for better accuracy"""
        print("Starting Enhanced Benchmark with Multiple Iterations...\n")
        
        # Test configurations with multiple runs
        test_configs = [
            ("Matrix Mult 512x512", 
             self.pytorch_matrix_multiplication, self.tensorflow_matrix_multiplication,
             (512, 512), (512, 512)),
            ("Matrix Mult 1024x1024", 
             self.pytorch_matrix_multiplication, self.tensorflow_matrix_multiplication,
             (1024, 1024), (1024, 1024)),
            ("Matrix Mult 2048x2048", 
             self.pytorch_matrix_multiplication, self.tensorflow_matrix_multiplication,
             (2048, 2048), (2048, 2048)),
            ("Conv2D (1,3,224,224)", 
             self.pytorch_convolution_2d, self.tensorflow_convolution_2d,
             1, 3, 224, 224),
            ("Conv2D (8,64,128,128)", 
             self.pytorch_convolution_2d, self.tensorflow_convolution_2d,
             8, 64, 128, 128),
            ("Element-wise (1000,1000)", 
             self.pytorch_element_wise_operations, self.tensorflow_element_wise_operations,
             (1000, 1000)),
            ("Element-wise (5000,5000)", 
             self.pytorch_element_wise_operations, self.tensorflow_element_wise_operations,
             (5000, 5000)),
        ]
        
        for config in test_configs:
            test_name = config[0]
            pytorch_func = config[1]
            tensorflow_func = config[2]
            test_args = config[3:]
            
            print(f"Running: {test_name}")
            try:
                results = self.benchmark_operation_enhanced(test_name, pytorch_func, tensorflow_func, *test_args)
                self.print_enhanced_results(test_name, results)
                
                # Clean up memory
                gc.collect()
                tf.keras.backend.clear_session()
                
            except Exception as e:
                print(f"Error in {test_name}: {e}")
            
            print("-" * 50)

    def benchmark_operation_enhanced(self, operation_name: str, pytorch_func, tensorflow_func, *args, **kwargs) -> Dict[str, float]:
        """Enhanced benchmark with multiple iterations and statistical analysis"""
        results = {}
        num_iterations = 10
        
        # PyTorch GPU Benchmark - Multiple iterations
        pytorch_gpu_times = []
        try:
            # Extended warm up
            for _ in range(5):
                pytorch_func(*args, device=self.pytorch_gpu_device, **kwargs)
            
            for i in range(num_iterations):
                start_time = time.perf_counter()
                result_pytorch_gpu = pytorch_func(*args, device=self.pytorch_gpu_device, **kwargs)
                pytorch_gpu_time = time.perf_counter() - start_time
                pytorch_gpu_times.append(pytorch_gpu_time)
                
                if i % 3 == 0:  # Periodic cleanup
                    gc.collect()
            
            results['pytorch_gpu_times'] = pytorch_gpu_times
            results['pytorch_gpu_mean'] = np.mean(pytorch_gpu_times)
            results['pytorch_gpu_std'] = np.std(pytorch_gpu_times)
            results['pytorch_gpu_min'] = np.min(pytorch_gpu_times)
            
        except Exception as e:
            print(f"PyTorch GPU benchmark failed for {operation_name}: {e}")
            results['pytorch_gpu_mean'] = float('inf')
            results['pytorch_gpu_std'] = 0
            results['pytorch_gpu_min'] = float('inf')
        
        # PyTorch CPU Benchmark - Multiple iterations
        pytorch_cpu_times = []
        try:
            # Extended warm up
            for _ in range(5):
                pytorch_func(*args, device=self.pytorch_cpu_device, **kwargs)
            
            for i in range(num_iterations):
                start_time = time.perf_counter()
                result_pytorch_cpu = pytorch_func(*args, device=self.pytorch_cpu_device, **kwargs)
                pytorch_cpu_time = time.perf_counter() - start_time
                pytorch_cpu_times.append(pytorch_cpu_time)
                
                if i % 3 == 0:
                    gc.collect()
            
            results['pytorch_cpu_times'] = pytorch_cpu_times
            results['pytorch_cpu_mean'] = np.mean(pytorch_cpu_times)
            results['pytorch_cpu_std'] = np.std(pytorch_cpu_times)
            results['pytorch_cpu_min'] = np.min(pytorch_cpu_times)
            
        except Exception as e:
            print(f"PyTorch CPU benchmark failed for {operation_name}: {e}")
            results['pytorch_cpu_mean'] = float('inf')
            results['pytorch_cpu_std'] = 0
            results['pytorch_cpu_min'] = float('inf')
        
        # TensorFlow GPU Benchmark - Multiple iterations
        tensorflow_gpu_times = []
        try:
            if self.tf_gpu_devices:
                with tf.device('/GPU:0'):
                    # Extended warm up
                    for _ in range(5):
                        tensorflow_func(*args, **kwargs)
                    
                    for i in range(num_iterations):
                        start_time = time.perf_counter()
                        result_tf_gpu = tensorflow_func(*args, **kwargs)
                        tf_gpu_time = time.perf_counter() - start_time
                        tensorflow_gpu_times.append(tf_gpu_time)
                        
                        if i % 3 == 0:
                            gc.collect()
                            tf.keras.backend.clear_session()
                    
                    results['tensorflow_gpu_times'] = tensorflow_gpu_times
                    results['tensorflow_gpu_mean'] = np.mean(tensorflow_gpu_times)
                    results['tensorflow_gpu_std'] = np.std(tensorflow_gpu_times)
                    results['tensorflow_gpu_min'] = np.min(tensorflow_gpu_times)
            else:
                results['tensorflow_gpu_mean'] = float('inf')
                results['tensorflow_gpu_std'] = 0
                results['tensorflow_gpu_min'] = float('inf')
                
        except Exception as e:
            print(f"TensorFlow GPU benchmark failed for {operation_name}: {e}")
            results['tensorflow_gpu_mean'] = float('inf')
            results['tensorflow_gpu_std'] = 0
            results['tensorflow_gpu_min'] = float('inf')
        
        # TensorFlow CPU Benchmark - Multiple iterations
        tensorflow_cpu_times = []
        try:
            with tf.device('/CPU:0'):
                # Extended warm up
                for _ in range(5):
                    tensorflow_func(*args, **kwargs)
                
                for i in range(num_iterations):
                    start_time = time.perf_counter()
                    result_tf_cpu = tensorflow_func(*args, **kwargs)
                    tf_cpu_time = time.perf_counter() - start_time
                    tensorflow_cpu_times.append(tf_cpu_time)
                    
                    if i % 3 == 0:
                        gc.collect()
                        tf.keras.backend.clear_session()
                
                results['tensorflow_cpu_times'] = tensorflow_cpu_times
                results['tensorflow_cpu_mean'] = np.mean(tensorflow_cpu_times)
                results['tensorflow_cpu_std'] = np.std(tensorflow_cpu_times)
                results['tensorflow_cpu_min'] = np.min(tensorflow_cpu_times)
                
        except Exception as e:
            print(f"TensorFlow CPU benchmark failed for {operation_name}: {e}")
            results['tensorflow_cpu_mean'] = float('inf')
            results['tensorflow_cpu_std'] = 0
            results['tensorflow_cpu_min'] = float('inf')
        
        # Calculate speedups using mean times
        if results['pytorch_cpu_mean'] != float('inf') and results['pytorch_gpu_mean'] != float('inf'):
            results['pytorch_speedup'] = results['pytorch_cpu_mean'] / results['pytorch_gpu_mean']
        else:
            results['pytorch_speedup'] = 0
            
        if results['tensorflow_cpu_mean'] != float('inf') and results['tensorflow_gpu_mean'] != float('inf'):
            results['tensorflow_speedup'] = results['tensorflow_cpu_mean'] / results['tensorflow_gpu_mean']
        else:
            results['tensorflow_speedup'] = 0
        
        # GPU vs GPU comparison using best times
        if results['pytorch_gpu_min'] != float('inf') and results['tensorflow_gpu_min'] != float('inf'):
            results['gpu_comparison'] = results['tensorflow_gpu_min'] / results['pytorch_gpu_min']
        else:
            results['gpu_comparison'] = 0
        
        self.results[operation_name] = results
        return results

    def print_results(self, test_name: str, results: Dict[str, float]):
        """Print benchmark results"""
        pytorch_cpu_time = results.get('pytorch_cpu_time', float('inf'))
        pytorch_gpu_time = results.get('pytorch_gpu_time', float('inf'))
        tensorflow_cpu_time = results.get('tensorflow_cpu_time', float('inf'))
        tensorflow_gpu_time = results.get('tensorflow_gpu_time', float('inf'))
        
        pytorch_speedup = results.get('pytorch_speedup', 0)
        tensorflow_speedup = results.get('tensorflow_speedup', 0)
        gpu_comparison = results.get('gpu_comparison', 0)
        
        print(f"  PyTorch CPU:    {pytorch_cpu_time:.4f}s")
        print(f"  PyTorch GPU:    {pytorch_gpu_time:.4f}s (Speedup: {pytorch_speedup:.2f}x)")
        print(f"  TensorFlow CPU: {tensorflow_cpu_time:.4f}s")
        print(f"  TensorFlow GPU: {tensorflow_gpu_time:.4f}s (Speedup: {tensorflow_speedup:.2f}x)")
        
        if gpu_comparison > 0:
            if gpu_comparison > 1:
                print(f"  GPU Comparison: TensorFlow is {gpu_comparison:.2f}x slower than PyTorch")
            else:
                print(f"  GPU Comparison: TensorFlow is {1/gpu_comparison:.2f}x faster than PyTorch")

    def print_enhanced_results(self, test_name: str, results: Dict[str, float]):
        """Print enhanced benchmark results with statistics"""
        pytorch_cpu_mean = results.get('pytorch_cpu_mean', float('inf'))
        pytorch_gpu_mean = results.get('pytorch_gpu_mean', float('inf'))
        tensorflow_cpu_mean = results.get('tensorflow_cpu_mean', float('inf'))
        tensorflow_gpu_mean = results.get('tensorflow_gpu_mean', float('inf'))
        
        pytorch_cpu_std = results.get('pytorch_cpu_std', 0)
        pytorch_gpu_std = results.get('pytorch_gpu_std', 0)
        tensorflow_cpu_std = results.get('tensorflow_cpu_std', 0)
        tensorflow_gpu_std = results.get('tensorflow_gpu_std', 0)
        
        pytorch_speedup = results.get('pytorch_speedup', 0)
        tensorflow_speedup = results.get('tensorflow_speedup', 0)
        gpu_comparison = results.get('gpu_comparison', 0)
        
        print(f"  PyTorch CPU:    {pytorch_cpu_mean:.4f}±{pytorch_cpu_std:.4f}s")
        print(f"  PyTorch GPU:    {pytorch_gpu_mean:.4f}±{pytorch_gpu_std:.4f}s (Speedup: {pytorch_speedup:.2f}x)")
        print(f"  TensorFlow CPU: {tensorflow_cpu_mean:.4f}±{tensorflow_cpu_std:.4f}s")
        print(f"  TensorFlow GPU: {tensorflow_gpu_mean:.4f}±{tensorflow_gpu_std:.4f}s (Speedup: {tensorflow_speedup:.2f}x)")
        
        if gpu_comparison > 0:
            if gpu_comparison > 1:
                print(f"  GPU Comparison: TensorFlow is {gpu_comparison:.2f}x slower than PyTorch")
            else:
                print(f"  GPU Comparison: TensorFlow is {1/gpu_comparison:.2f}x faster than PyTorch")

    def generate_report(self):
        """Generate comprehensive performance report"""
        print("\n" + "="*80)
        print("PYTORCH vs TENSORFLOW PERFORMANCE SUMMARY REPORT")
        print("="*80)
        
        pytorch_gpu_faster = []
        tensorflow_gpu_faster = []
        
        for test_name, results in self.results.items():
            gpu_comparison = results.get('gpu_comparison', 0)
            if gpu_comparison > 1:
                tensorflow_gpu_faster.append((test_name, 1/gpu_comparison))
            elif gpu_comparison < 1 and gpu_comparison > 0:
                pytorch_gpu_faster.append((test_name, gpu_comparison))
        
        # Sort by speedup
        pytorch_gpu_faster.sort(key=lambda x: x[1], reverse=True)
        tensorflow_gpu_faster.sort(key=lambda x: x[1], reverse=True)
        
        print("\nGPU TESTS WHERE PYTORCH IS FASTER:")
        for test_name, speedup in pytorch_gpu_faster:
            print(f"  {test_name}: {1/speedup:.2f}x faster")
        
        print("\nGPU TESTS WHERE TENSORFLOW IS FASTER:")
        for test_name, speedup in tensorflow_gpu_faster:
            print(f"  {test_name}: {speedup:.2f}x faster")
        
        # Overall statistics
        pytorch_speedups = [r.get('pytorch_speedup', 0) for r in self.results.values() if r.get('pytorch_speedup', 0) > 0]
        tensorflow_speedups = [r.get('tensorflow_speedup', 0) for r in self.results.values() if r.get('tensorflow_speedup', 0) > 0]
        
        if pytorch_speedups and tensorflow_speedups:
            avg_pytorch_speedup = np.mean(pytorch_speedups)
            avg_tensorflow_speedup = np.mean(tensorflow_speedups)
            
            print(f"\nOVERALL STATISTICS:")
            print(f"  Average PyTorch GPU Speedup: {avg_pytorch_speedup:.2f}x")
            print(f"  Average TensorFlow GPU Speedup: {avg_tensorflow_speedup:.2f}x")
            print(f"  PyTorch GPU wins: {len(pytorch_gpu_faster)} tests")
            print(f"  TensorFlow GPU wins: {len(tensorflow_gpu_faster)} tests")

    def generate_detailed_report(self):
        """Generate detailed performance report with statistical analysis"""
        print("\n" + "="*80)
        print("ENHANCED PYTORCH vs TENSORFLOW PERFORMANCE REPORT")
        print("="*80)
        
        # Analyze consistency
        print("\nPERFORMANCE CONSISTENCY ANALYSIS:")
        for test_name, results in self.results.items():
            pytorch_gpu_std = results.get('pytorch_gpu_std', 0)
            tensorflow_gpu_std = results.get('tensorflow_gpu_std', 0)
            pytorch_gpu_mean = results.get('pytorch_gpu_mean', float('inf'))
            tensorflow_gpu_mean = results.get('tensorflow_gpu_mean', float('inf'))
            
            if pytorch_gpu_mean != float('inf') and tensorflow_gpu_mean != float('inf'):
                pytorch_cv = (pytorch_gpu_std / pytorch_gpu_mean) * 100 if pytorch_gpu_mean > 0 else 0
                tensorflow_cv = (tensorflow_gpu_std / tensorflow_gpu_mean) * 100 if tensorflow_gpu_mean > 0 else 0
                
                print(f"  {test_name}:")
                print(f"    PyTorch GPU CV: {pytorch_cv:.2f}%")
                print(f"    TensorFlow GPU CV: {tensorflow_cv:.2f}%")
        
        # Rest of the original report logic...
        pytorch_gpu_faster = []
        tensorflow_gpu_faster = []
        
        for test_name, results in self.results.items():
            gpu_comparison = results.get('gpu_comparison', 0)
            if gpu_comparison > 1:
                pytorch_gpu_faster.append((test_name, gpu_comparison))
            elif gpu_comparison < 1 and gpu_comparison > 0:
                tensorflow_gpu_faster.append((test_name, 1/gpu_comparison))
        
        print(f"\nGPU TESTS WHERE PYTORCH IS FASTER:")
        for test_name, speedup in pytorch_gpu_faster:
            print(f"  {test_name}: {speedup:.2f}x faster")
        
        print(f"\nGPU TESTS WHERE TENSORFLOW IS FASTER:")
        for test_name, speedup in tensorflow_gpu_faster:
            print(f"  {test_name}: {speedup:.2f}x faster")

    def plot_comparison(self):
        """Plot PyTorch vs TensorFlow comparison"""
        if not self.results:
            print("No results to plot")
            return
        
        test_names = list(self.results.keys())
        pytorch_gpu_times = [self.results[name].get('pytorch_gpu_time', 0) for name in test_names]
        tensorflow_gpu_times = [self.results[name].get('tensorflow_gpu_time', 0) for name in test_names]
        
        # Filter out infinite values
        valid_indices = [i for i, (p, t) in enumerate(zip(pytorch_gpu_times, tensorflow_gpu_times)) 
                        if p != float('inf') and t != float('inf')]
        
        if not valid_indices:
            print("No valid results to plot")
            return
        
        test_names = [test_names[i] for i in valid_indices]
        pytorch_gpu_times = [pytorch_gpu_times[i] for i in valid_indices]
        tensorflow_gpu_times = [tensorflow_gpu_times[i] for i in valid_indices]
        
        # Create plots
        fig, (ax1, ax2) = plt.subplots(2, 1, figsize=(14, 12))
        
        # Plot 1: GPU Execution times comparison
        x = np.arange(len(test_names))
        width = 0.35
        
        ax1.bar(x - width/2, pytorch_gpu_times, width, label='PyTorch GPU', alpha=0.8, color='orange')
        ax1.bar(x + width/2, tensorflow_gpu_times, width, label='TensorFlow GPU', alpha=0.8, color='blue')
        ax1.set_xlabel('Test Cases')
        ax1.set_ylabel('Time (seconds)')
        ax1.set_title('PyTorch vs TensorFlow GPU Performance')
        ax1.set_xticks(x)
        ax1.set_xticklabels(test_names, rotation=45, ha='right')
        ax1.legend()
        ax1.grid(True, alpha=0.3)
        
        # Plot 2: Relative performance (TensorFlow time / PyTorch time)
        relative_performance = [tensorflow_gpu_times[i] / pytorch_gpu_times[i] for i in range(len(test_names))]
        colors = ['green' if r < 1 else 'red' for r in relative_performance]
        
        ax2.bar(x, relative_performance, color=colors, alpha=0.7)
        ax2.axhline(y=1, color='black', linestyle='--', alpha=0.5)
        ax2.set_xlabel('Test Cases')
        ax2.set_ylabel('Relative Performance (TF GPU Time / PyTorch GPU Time)')
        ax2.set_title('TensorFlow vs PyTorch GPU Relative Performance\n(Values < 1 mean TensorFlow is faster)')
        ax2.set_xticks(x)
        ax2.set_xticklabels(test_names, rotation=45, ha='right')
        ax2.grid(True, alpha=0.3)
        
        plt.tight_layout()
        plt.savefig('pytorch_vs_tensorflow_directml_benchmark.png', dpi=300, bbox_inches='tight')
        plt.show()

    def plot_enhanced_comparison(self):
        """Plot enhanced PyTorch vs TensorFlow comparison with error bars"""
        if not self.results:
            print("No results to plot")
            return
        
        test_names = list(self.results.keys())
        pytorch_gpu_means = [self.results[name].get('pytorch_gpu_mean', 0) for name in test_names]
        tensorflow_gpu_means = [self.results[name].get('tensorflow_gpu_mean', 0) for name in test_names]
        pytorch_gpu_stds = [self.results[name].get('pytorch_gpu_std', 0) for name in test_names]
        tensorflow_gpu_stds = [self.results[name].get('tensorflow_gpu_std', 0) for name in test_names]
        
        # Filter out infinite values
        valid_indices = [i for i, (p, t) in enumerate(zip(pytorch_gpu_means, tensorflow_gpu_means)) 
                        if p != float('inf') and t != float('inf')]
        
        if not valid_indices:
            print("No valid results to plot")
            return
        
        test_names = [test_names[i] for i in valid_indices]
        pytorch_gpu_means = [pytorch_gpu_means[i] for i in valid_indices]
        tensorflow_gpu_means = [tensorflow_gpu_means[i] for i in valid_indices]
        pytorch_gpu_stds = [pytorch_gpu_stds[i] for i in valid_indices]
        tensorflow_gpu_stds = [tensorflow_gpu_stds[i] for i in valid_indices]
        
        # Create plots
        fig, (ax1, ax2) = plt.subplots(2, 1, figsize=(14, 12))
        
        # Plot 1: GPU Execution times comparison with error bars
        x = np.arange(len(test_names))
        width = 0.35
        
        ax1.bar(x - width/2, pytorch_gpu_means, width, yerr=pytorch_gpu_stds, 
                label='PyTorch GPU', alpha=0.8, color='orange', capsize=5)
        ax1.bar(x + width/2, tensorflow_gpu_means, width, yerr=tensorflow_gpu_stds,
                label='TensorFlow GPU', alpha=0.8, color='blue', capsize=5)
        ax1.set_xlabel('Test Cases')
        ax1.set_ylabel('Time (seconds)')
        ax1.set_title('PyTorch vs TensorFlow GPU Performance (Enhanced)')
        ax1.set_xticks(x)
        ax1.set_xticklabels(test_names, rotation=45, ha='right')
        ax1.legend()
        ax1.grid(True, alpha=0.3)
        
        # Plot 2: Relative performance with confidence intervals
        relative_performance = [tensorflow_gpu_means[i] / pytorch_gpu_means[i] for i in range(len(test_names))]
        colors = ['green' if r < 1 else 'red' for r in relative_performance]
        
        ax2.bar(x, relative_performance, color=colors, alpha=0.7)
        ax2.axhline(y=1, color='black', linestyle='--', alpha=0.5)
        ax2.set_xlabel('Test Cases')
        ax2.set_ylabel('Relative Performance (TF GPU Time / PyTorch GPU Time)')
        ax2.set_title('TensorFlow vs PyTorch GPU Relative Performance (Enhanced)\n(Values < 1 mean TensorFlow is faster)')
        ax2.set_xticks(x)
        ax2.set_xticklabels(test_names, rotation=45, ha='right')
        ax2.grid(True, alpha=0.3)
        
        plt.tight_layout()
        plt.savefig('pytorch_vs_tensorflow_directml_enhanced_benchmark.png', dpi=300, bbox_inches='tight')
        plt.show()

def main():
    """Main function to run benchmarks"""
    try:
        benchmark = UnifiedBenchmark()
        
        print("Choose benchmark type:")
        print("1. Comprehensive PyTorch vs TensorFlow benchmark")
        print("2. Quick comparison test")
        print("3. Enhanced benchmark with improved accuracy")
        
        choice = input("Enter choice (1-3): ").strip()
        
        if choice == "1":
            benchmark.run_comprehensive_benchmark()
            benchmark.generate_report()
            
            # Ask if user wants to plot results
            plot_choice = input("\nGenerate comparison plots? (y/n): ").strip().lower()
            if plot_choice == 'y':
                try:
                    benchmark.plot_comparison()
                except ImportError:
                    print("Matplotlib not available for plotting")
                except Exception as e:
                    print(f"Error generating plots: {e}")
        
        elif choice == "2":
            # Quick test
            print("Running quick comparison test...")
            results = benchmark.benchmark_operation(
                "Quick Test Matrix Mult (1000x1000)",
                benchmark.pytorch_matrix_multiplication,
                benchmark.tensorflow_matrix_multiplication,
                (1000, 1000), (1000, 1000)
            )
            benchmark.print_results("Quick Test", results)
            
        elif choice == "3":
            # Enhanced benchmark with improved accuracy
            benchmark.run_enhanced_benchmark()
            benchmark.generate_detailed_report()
            
            plot_choice = input("\nGenerate enhanced comparison plots? (y/n): ").strip().lower()
            if plot_choice == 'y':
                try:
                    benchmark.plot_enhanced_comparison()
                except ImportError:
                    print("Matplotlib not available for plotting")
                except Exception as e:
                    print(f"Error generating plots: {e}")
                
    except Exception as e:
        print(f"Error running benchmark: {e}")
        print("Make sure both torch-directml and tensorflow-directml are installed:")
        print("pip install torch-directml tensorflow-directml")

if __name__ == "__main__":
    main()