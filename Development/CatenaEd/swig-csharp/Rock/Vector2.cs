/* ----------------------------------------------------------------------------
 * This file was automatically generated by SWIG (http://www.swig.org).
 * Version 3.0.0
 *
 * Do not make changes to this file unless you know what you are doing--modify
 * the SWIG interface file instead.
 * ----------------------------------------------------------------------------- */

namespace Rock {

public class Vector2 : global::System.IDisposable {
  private global::System.Runtime.InteropServices.HandleRef swigCPtr;
  protected bool swigCMemOwn;

  internal Vector2(global::System.IntPtr cPtr, bool cMemoryOwn) {
    swigCMemOwn = cMemoryOwn;
    swigCPtr = new global::System.Runtime.InteropServices.HandleRef(this, cPtr);
  }

  internal static global::System.Runtime.InteropServices.HandleRef getCPtr(Vector2 obj) {
    return (obj == null) ? new global::System.Runtime.InteropServices.HandleRef(null, global::System.IntPtr.Zero) : obj.swigCPtr;
  }

  ~Vector2() {
    Dispose();
  }

  public virtual void Dispose() {
    lock(this) {
      if (swigCPtr.Handle != global::System.IntPtr.Zero) {
        if (swigCMemOwn) {
          swigCMemOwn = false;
          RockPINVOKE.delete_Vector2(swigCPtr);
        }
        swigCPtr = new global::System.Runtime.InteropServices.HandleRef(null, global::System.IntPtr.Zero);
      }
      global::System.GC.SuppressFinalize(this);
    }
  }

  public float x {
    set {
      RockPINVOKE.Vector2_x_set(swigCPtr, value);
    } 
    get {
      float ret = RockPINVOKE.Vector2_x_get(swigCPtr);
      return ret;
    } 
  }

  public float y {
    set {
      RockPINVOKE.Vector2_y_set(swigCPtr, value);
    } 
    get {
      float ret = RockPINVOKE.Vector2_y_get(swigCPtr);
      return ret;
    } 
  }

  public Vector2() : this(RockPINVOKE.new_Vector2__SWIG_0(), true) {
  }

  public Vector2(float v) : this(RockPINVOKE.new_Vector2__SWIG_1(v), true) {
  }

  public Vector2(float x, float y) : this(RockPINVOKE.new_Vector2__SWIG_2(x, y), true) {
  }

  public Vector2(Vector2 vCopy) : this(RockPINVOKE.new_Vector2__SWIG_3(Vector2.getCPtr(vCopy)), true) {
    if (RockPINVOKE.SWIGPendingException.Pending) throw RockPINVOKE.SWIGPendingException.Retrieve();
  }

}

}
