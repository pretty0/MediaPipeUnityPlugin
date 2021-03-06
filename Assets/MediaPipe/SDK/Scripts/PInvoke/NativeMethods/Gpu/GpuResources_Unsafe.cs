using System;
using System.Runtime.InteropServices;

namespace Mediapipe {
  internal static partial class UnsafeNativeMethods {
    [DllImport (MediaPipeLibrary, ExactSpelling = true)]
    public static extern void mp_SharedGpuResources__delete(IntPtr gpuResources);

    [DllImport (MediaPipeLibrary, ExactSpelling = true)]
    public static extern void mp_SharedGpuResources__reset(IntPtr gpuResources);

    [DllImport (MediaPipeLibrary, ExactSpelling = true)]
    public static extern MpReturnCode mp_GpuResources_Create(out IntPtr statusOrGpuResources);

    [DllImport (MediaPipeLibrary, ExactSpelling = true)]
    public static extern void mp_StatusOrGpuResources__delete(IntPtr statusOrGpuResources);

    [DllImport (MediaPipeLibrary, ExactSpelling = true)]
    public static extern MpReturnCode mp_StatusOrGpuResources__status(IntPtr statusOrGpuResources, out IntPtr status);

    [DllImport (MediaPipeLibrary, ExactSpelling = true)]
    public static extern MpReturnCode mp_StatusOrGpuResources__ValueOrDie(IntPtr statusOrGpuResources, out IntPtr gpuResources);

    [DllImport (MediaPipeLibrary, ExactSpelling = true)]
    public static extern MpReturnCode mp_StatusOrGpuResources__ConsumeValueOrDie(IntPtr statusOrGpuResources, out IntPtr gpuResources);
  }
}
