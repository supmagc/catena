/* ----------------------------------------------------------------------------
 * This file was automatically generated by SWIG (http://www.swig.org).
 * Version 3.0.0
 *
 * Do not make changes to this file unless you know what you are doing--modify
 * the SWIG interface file instead.
 * ----------------------------------------------------------------------------- */


public class Rock {
  public static SWIGTYPE_p_DLL_EXPORT Matrix4x4 {
    set {
      RockPINVOKE.Matrix4x4_set(SWIGTYPE_p_DLL_EXPORT.getCPtr(value));
      if (RockPINVOKE.SWIGPendingException.Pending) throw RockPINVOKE.SWIGPendingException.Retrieve();
    } 
    get {
      SWIGTYPE_p_DLL_EXPORT ret = new SWIGTYPE_p_DLL_EXPORT(RockPINVOKE.Matrix4x4_get(), true);
      if (RockPINVOKE.SWIGPendingException.Pending) throw RockPINVOKE.SWIGPendingException.Retrieve();
      return ret;
    } 
  }

}
