#include <utility>
#include "mediapipe_api/framework/calculator_graph.h"

MpReturnCode mp_CalculatorGraph__(mediapipe::CalculatorGraph** graph_out) {
  TRY {
    *graph_out = new mediapipe::CalculatorGraph();
    RETURN_CODE(MpReturnCode::Success);
  } CATCH_EXCEPTION
}

void mp_CalculatorGraph__delete(mediapipe::CalculatorGraph* graph) {
  delete graph;
}

MpReturnCode mp_CalculatorGraph__Rconfig(mediapipe::CalculatorGraphConfig* config, mediapipe::CalculatorGraph** graph_out) {
  TRY_ALL {
    *graph_out = new mediapipe::CalculatorGraph(*config);
    RETURN_CODE(MpReturnCode::Success);
  } CATCH_ALL
}

MpReturnCode mp_CalculatorGraph__Initialize__Rconfig(mediapipe::CalculatorGraph* graph,
                                                     mediapipe::CalculatorGraphConfig* config,
                                                     mediapipe::Status** status_out) {
  TRY_ALL {
    *status_out = new mediapipe::Status { graph->Initialize(*config) };
    RETURN_CODE(MpReturnCode::Success);
  } CATCH_ALL
}

MpReturnCode mp_CalculatorGraph__Initialize__Rconfig_Rsp(
    mediapipe::CalculatorGraph* graph,
    mediapipe::CalculatorGraphConfig* config,
    SidePackets* side_packets,
    mediapipe::Status** status_out) {
  TRY_ALL {
    *status_out = new mediapipe::Status { graph->Initialize(*config, *side_packets) };
    RETURN_CODE(MpReturnCode::Success);
  } CATCH_ALL
}

MpReturnCode mp_CalculatorGraph__Config(mediapipe::CalculatorGraph* graph, mediapipe::CalculatorGraphConfig** config_out) {
  TRY_ALL {
    *config_out = new mediapipe::CalculatorGraphConfig { graph->Config() };  // Crashes if graph has no config
    RETURN_CODE(MpReturnCode::Success);
  } CATCH_ALL
}

MpReturnCode mp_CalculatorGraph__AddOutputStreamPoller__PKc(mediapipe::CalculatorGraph* graph,
                                                            const char* stream_name,
                                                            mediapipe::StatusOrPoller** status_or_poller_out) {
  TRY {
    *status_or_poller_out = new mediapipe::StatusOrPoller { graph->AddOutputStreamPoller(stream_name) };
    RETURN_CODE(MpReturnCode::Success);
  } CATCH_EXCEPTION
}

MpReturnCode mp_CalculatorGraph__Run__Rsp(mediapipe::CalculatorGraph* graph,
                                          SidePackets* side_packets,
                                          mediapipe::Status** status_out) {
  TRY {
    auto status = graph->Run(*side_packets);
    *status_out = new mediapipe::Status { std::move(status) };
    RETURN_CODE(MpReturnCode::Success);
  } CATCH_EXCEPTION
}

MpReturnCode mp_CalculatorGraph__StartRun__Rsp(mediapipe::CalculatorGraph* graph,
                                               SidePackets* side_packets,
                                               mediapipe::Status** status_out) {
  TRY {
    auto status = graph->StartRun(*side_packets);
    *status_out = new mediapipe::Status { std::move(status) };
    RETURN_CODE(MpReturnCode::Success);
  } CATCH_EXCEPTION
}

MpReturnCode mp_CalculatorGraph__WaitUntilIdle(mediapipe::CalculatorGraph* graph, mediapipe::Status** status_out) {
  TRY {
    auto status = graph->WaitUntilIdle();
    *status_out = new mediapipe::Status { std::move(status) };
    RETURN_CODE(MpReturnCode::Success);
  } CATCH_EXCEPTION
}

MpReturnCode mp_CalculatorGraph__WaitUntilDone(mediapipe::CalculatorGraph* graph, mediapipe::Status** status_out) {
  TRY {
    auto status = graph->WaitUntilDone();
    *status_out = new mediapipe::Status { std::move(status) };
    RETURN_CODE(MpReturnCode::Success);
  } CATCH_EXCEPTION
}

bool mp_CalculatorGraph__HasError(mediapipe::CalculatorGraph* graph) {
  return graph->HasError();
}

MpReturnCode mp_CalculatorGraph__AddPacketToInputStream__PKc_Ppacket(mediapipe::CalculatorGraph* graph,
                                                                     const char* stream_name,
                                                                     mediapipe::Packet* packet,
                                                                     mediapipe::Status** status_out) {
  TRY {
    *status_out = new mediapipe::Status { graph->AddPacketToInputStream(stream_name, std::move(*packet)) };
    RETURN_CODE(MpReturnCode::Success);
  } CATCH_EXCEPTION
}

MpReturnCode mp_CalculatorGraph__SetInputStreamMaxQueueSize__PKc_i(mediapipe::CalculatorGraph* graph,
                                                                   const char* stream_name,
                                                                   int max_queue_size,
                                                                   mediapipe::Status** status_out) {
  TRY {
    *status_out = new mediapipe::Status { graph->SetInputStreamMaxQueueSize(stream_name, max_queue_size) };
    RETURN_CODE(MpReturnCode::Success);
  } CATCH_EXCEPTION
}

bool mp_CalculatorGraph__HasInputStream__PKc(mediapipe::CalculatorGraph* graph, const char* name) {
  return graph->HasInputStream(name);
}

MpReturnCode mp_CalculatorGraph__CloseInputStream__PKc(mediapipe::CalculatorGraph* graph,
                                                       const char* stream_name,
                                                       mediapipe::Status** status_out) {
  TRY {
    *status_out = new mediapipe::Status { graph->CloseInputStream(stream_name) };
    RETURN_CODE(MpReturnCode::Success);
  } CATCH_EXCEPTION
}

MpReturnCode mp_CalculatorGraph__CloseAllPacketSources(mediapipe::CalculatorGraph* graph, mediapipe::Status** status_out) {
  TRY {
    *status_out = new mediapipe::Status { graph->CloseAllPacketSources() };
    RETURN_CODE(MpReturnCode::Success);
  } CATCH_EXCEPTION
}

MpReturnCode mp_CalculatorGraph__Cancel(mediapipe::CalculatorGraph* graph) {
  TRY {
    graph->Cancel();
    RETURN_CODE(MpReturnCode::Success);
  } CATCH_EXCEPTION
}

bool mp_CalculatorGraph__GraphInputStreamsClosed(mediapipe::CalculatorGraph* graph) {
  return graph->GraphInputStreamsClosed();
}

bool mp_CalculatorGraph__IsNodeThrottled__i(mediapipe::CalculatorGraph* graph, int node_id) {
  return graph->IsNodeThrottled(node_id);
}

bool mp_CalculatorGraph__UnthrottleSources(mediapipe::CalculatorGraph* graph) {
  return graph->UnthrottleSources();
}

#ifndef MEDIAPIPE_DISABLE_GPU
MpReturnCode mp_CalculatorGraph__GetGpuResources(mediapipe::CalculatorGraph* graph,
                                                 std::shared_ptr<mediapipe::GpuResources>** gpu_resources_out) {
  TRY {
    auto gpu_resources = graph->GetGpuResources();
    *gpu_resources_out = new std::shared_ptr<mediapipe::GpuResources> { gpu_resources };
    RETURN_CODE(MpReturnCode::Success);
  } CATCH_EXCEPTION
}

MpReturnCode mp_CalculatorGraph__SetGpuResources__SPgpu(mediapipe::CalculatorGraph* graph,
                                                        std::shared_ptr<mediapipe::GpuResources>* gpu_resources,
                                                        mediapipe::Status** status_out) {
  TRY_ALL {
    *status_out = new mediapipe::Status { graph->SetGpuResources(*gpu_resources) };
    RETURN_CODE(MpReturnCode::Success);
  } CATCH_ALL
}
#endif  // !defined(MEDIAPIPE_DISABLE_GPU)
