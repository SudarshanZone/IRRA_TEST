//ApplicationServer\Open_Pos\internal\positions\fno_pos.proto

// Code generated by protoc-gen-go. DO NOT EDIT.
// versions:
// 	protoc-gen-go v1.34.2
// 	protoc        v5.27.1
// source: positions/fno_pos.proto

package __

import (
	protoreflect "google.golang.org/protobuf/reflect/protoreflect"
	protoimpl "google.golang.org/protobuf/runtime/protoimpl"
	reflect "reflect"
	sync "sync"
)

const (
	// Verify that this generated code is sufficiently up-to-date.
	_ = protoimpl.EnforceVersion(20 - protoimpl.MinVersion)
	// Verify that runtime/protoimpl is sufficiently up-to-date.
	_ = protoimpl.EnforceVersion(protoimpl.MaxVersion - 20)
)

type FnoPositionRequest struct {
	state         protoimpl.MessageState
	sizeCache     protoimpl.SizeCache
	unknownFields protoimpl.UnknownFields

	FCP_CLM_MTCH_ACCNT string `protobuf:"bytes,1,opt,name=FCP_CLM_MTCH_ACCNT,json=FCPCLMMTCHACCNT,proto3" json:"FCP_CLM_MTCH_ACCNT,omitempty"`
}

func (x *FnoPositionRequest) Reset() {
	*x = FnoPositionRequest{}
	if protoimpl.UnsafeEnabled {
		mi := &file_positions_fno_pos_proto_msgTypes[0]
		ms := protoimpl.X.MessageStateOf(protoimpl.Pointer(x))
		ms.StoreMessageInfo(mi)
	}
}

func (x *FnoPositionRequest) String() string {
	return protoimpl.X.MessageStringOf(x)
}

func (*FnoPositionRequest) ProtoMessage() {}

func (x *FnoPositionRequest) ProtoReflect() protoreflect.Message {
	mi := &file_positions_fno_pos_proto_msgTypes[0]
	if protoimpl.UnsafeEnabled && x != nil {
		ms := protoimpl.X.MessageStateOf(protoimpl.Pointer(x))
		if ms.LoadMessageInfo() == nil {
			ms.StoreMessageInfo(mi)
		}
		return ms
	}
	return mi.MessageOf(x)
}

// Deprecated: Use FnoPositionRequest.ProtoReflect.Descriptor instead.
func (*FnoPositionRequest) Descriptor() ([]byte, []int) {
	return file_positions_fno_pos_proto_rawDescGZIP(), []int{0}
}

func (x *FnoPositionRequest) GetFCP_CLM_MTCH_ACCNT() string {
	if x != nil {
		return x.FCP_CLM_MTCH_ACCNT
	}
	return ""
}

type FcpDetail struct {
	state         protoimpl.MessageState
	sizeCache     protoimpl.SizeCache
	unknownFields protoimpl.UnknownFields

	FFO_CONTRACT       string  `protobuf:"bytes,1,opt,name=FFO_CONTRACT,json=FFOCONTRACT,proto3" json:"FFO_CONTRACT,omitempty"`
	FFO_PSTN           string  `protobuf:"bytes,2,opt,name=FFO_PSTN,json=FFOPSTN,proto3" json:"FFO_PSTN,omitempty"`
	FFO_QTY            int32   `protobuf:"varint,3,opt,name=FFO_QTY,json=FFOQTY,proto3" json:"FFO_QTY,omitempty"`
	FFO_AVG_PRC        float32 `protobuf:"fixed32,4,opt,name=FFO_AVG_PRC,json=FFOAVGPRC,proto3" json:"FFO_AVG_PRC,omitempty"`
	FCP_XCHNG_CD       string  `protobuf:"bytes,5,opt,name=FCP_XCHNG_CD,json=FCPXCHNGCD,proto3" json:"FCP_XCHNG_CD,omitempty"`
	FCP_IBUY_QTY       int32   `protobuf:"varint,6,opt,name=FCP_IBUY_QTY,json=FCPIBUYQTY,proto3" json:"FCP_IBUY_QTY,omitempty"`
	FCP_CLM_MTCH_ACCNT string  `protobuf:"bytes,7,opt,name=FCP_CLM_MTCH_ACCNT,json=FCPCLMMTCHACCNT,proto3" json:"FCP_CLM_MTCH_ACCNT,omitempty"`
	FCP_PRDCT_TYP      string  `protobuf:"bytes,8,opt,name=FCP_PRDCT_TYP,json=FCPPRDCTTYP,proto3" json:"FCP_PRDCT_TYP,omitempty"`
	FCP_INDSTK         string  `protobuf:"bytes,9,opt,name=FCP_INDSTK,json=FCPINDSTK,proto3" json:"FCP_INDSTK,omitempty"`
	FCP_UNDRLYNG       string  `protobuf:"bytes,10,opt,name=FCP_UNDRLYNG,json=FCPUNDRLYNG,proto3" json:"FCP_UNDRLYNG,omitempty"`
	FCP_EXPRY_DT       string  `protobuf:"bytes,11,opt,name=FCP_EXPRY_DT,json=FCPEXPRYDT,proto3" json:"FCP_EXPRY_DT,omitempty"`
	FCP_EXER_TYP       string  `protobuf:"bytes,12,opt,name=FCP_EXER_TYP,json=FCPEXERTYP,proto3" json:"FCP_EXER_TYP,omitempty"`
	FCP_OPT_TYP        string  `protobuf:"bytes,13,opt,name=FCP_OPT_TYP,json=FCPOPTTYP,proto3" json:"FCP_OPT_TYP,omitempty"`
	FCP_STRK_PRC       float32 `protobuf:"fixed32,14,opt,name=FCP_STRK_PRC,json=FCPSTRKPRC,proto3" json:"FCP_STRK_PRC,omitempty"`
	FCP_UCC_CD         string  `protobuf:"bytes,15,opt,name=FCP_UCC_CD,json=FCPUCCCD,proto3" json:"FCP_UCC_CD,omitempty"`
	FCP_OPNPSTN_FLW    string  `protobuf:"bytes,16,opt,name=FCP_OPNPSTN_FLW,json=FCPOPNPSTNFLW,proto3" json:"FCP_OPNPSTN_FLW,omitempty"`
}

func (x *FcpDetail) Reset() {
	*x = FcpDetail{}
	if protoimpl.UnsafeEnabled {
		mi := &file_positions_fno_pos_proto_msgTypes[1]
		ms := protoimpl.X.MessageStateOf(protoimpl.Pointer(x))
		ms.StoreMessageInfo(mi)
	}
}

func (x *FcpDetail) String() string {
	return protoimpl.X.MessageStringOf(x)
}

func (*FcpDetail) ProtoMessage() {}

func (x *FcpDetail) ProtoReflect() protoreflect.Message {
	mi := &file_positions_fno_pos_proto_msgTypes[1]
	if protoimpl.UnsafeEnabled && x != nil {
		ms := protoimpl.X.MessageStateOf(protoimpl.Pointer(x))
		if ms.LoadMessageInfo() == nil {
			ms.StoreMessageInfo(mi)
		}
		return ms
	}
	return mi.MessageOf(x)
}

// Deprecated: Use FcpDetail.ProtoReflect.Descriptor instead.
func (*FcpDetail) Descriptor() ([]byte, []int) {
	return file_positions_fno_pos_proto_rawDescGZIP(), []int{1}
}

func (x *FcpDetail) GetFFO_CONTRACT() string {
	if x != nil {
		return x.FFO_CONTRACT
	}
	return ""
}

func (x *FcpDetail) GetFFO_PSTN() string {
	if x != nil {
		return x.FFO_PSTN
	}
	return ""
}

func (x *FcpDetail) GetFFO_QTY() int32 {
	if x != nil {
		return x.FFO_QTY
	}
	return 0
}

func (x *FcpDetail) GetFFO_AVG_PRC() float32 {
	if x != nil {
		return x.FFO_AVG_PRC
	}
	return 0
}

func (x *FcpDetail) GetFCP_XCHNG_CD() string {
	if x != nil {
		return x.FCP_XCHNG_CD
	}
	return ""
}

func (x *FcpDetail) GetFCP_IBUY_QTY() int32 {
	if x != nil {
		return x.FCP_IBUY_QTY
	}
	return 0
}

func (x *FcpDetail) GetFCP_CLM_MTCH_ACCNT() string {
	if x != nil {
		return x.FCP_CLM_MTCH_ACCNT
	}
	return ""
}

func (x *FcpDetail) GetFCP_PRDCT_TYP() string {
	if x != nil {
		return x.FCP_PRDCT_TYP
	}
	return ""
}

func (x *FcpDetail) GetFCP_INDSTK() string {
	if x != nil {
		return x.FCP_INDSTK
	}
	return ""
}

func (x *FcpDetail) GetFCP_UNDRLYNG() string {
	if x != nil {
		return x.FCP_UNDRLYNG
	}
	return ""
}

func (x *FcpDetail) GetFCP_EXPRY_DT() string {
	if x != nil {
		return x.FCP_EXPRY_DT
	}
	return ""
}

func (x *FcpDetail) GetFCP_EXER_TYP() string {
	if x != nil {
		return x.FCP_EXER_TYP
	}
	return ""
}

func (x *FcpDetail) GetFCP_OPT_TYP() string {
	if x != nil {
		return x.FCP_OPT_TYP
	}
	return ""
}

func (x *FcpDetail) GetFCP_STRK_PRC() float32 {
	if x != nil {
		return x.FCP_STRK_PRC
	}
	return 0
}

func (x *FcpDetail) GetFCP_UCC_CD() string {
	if x != nil {
		return x.FCP_UCC_CD
	}
	return ""
}

func (x *FcpDetail) GetFCP_OPNPSTN_FLW() string {
	if x != nil {
		return x.FCP_OPNPSTN_FLW
	}
	return ""
}

type FcpDetailListResponse struct {
	state         protoimpl.MessageState
	sizeCache     protoimpl.SizeCache
	unknownFields protoimpl.UnknownFields

	FcpDetails []*FcpDetail `protobuf:"bytes,1,rep,name=FcpDetails,proto3" json:"FcpDetails,omitempty"`
}

func (x *FcpDetailListResponse) Reset() {
	*x = FcpDetailListResponse{}
	if protoimpl.UnsafeEnabled {
		mi := &file_positions_fno_pos_proto_msgTypes[2]
		ms := protoimpl.X.MessageStateOf(protoimpl.Pointer(x))
		ms.StoreMessageInfo(mi)
	}
}

func (x *FcpDetailListResponse) String() string {
	return protoimpl.X.MessageStringOf(x)
}

func (*FcpDetailListResponse) ProtoMessage() {}

func (x *FcpDetailListResponse) ProtoReflect() protoreflect.Message {
	mi := &file_positions_fno_pos_proto_msgTypes[2]
	if protoimpl.UnsafeEnabled && x != nil {
		ms := protoimpl.X.MessageStateOf(protoimpl.Pointer(x))
		if ms.LoadMessageInfo() == nil {
			ms.StoreMessageInfo(mi)
		}
		return ms
	}
	return mi.MessageOf(x)
}

// Deprecated: Use FcpDetailListResponse.ProtoReflect.Descriptor instead.
func (*FcpDetailListResponse) Descriptor() ([]byte, []int) {
	return file_positions_fno_pos_proto_rawDescGZIP(), []int{2}
}

func (x *FcpDetailListResponse) GetFcpDetails() []*FcpDetail {
	if x != nil {
		return x.FcpDetails
	}
	return nil
}

var File_positions_fno_pos_proto protoreflect.FileDescriptor

var file_positions_fno_pos_proto_rawDesc = []byte{
	0x0a, 0x17, 0x70, 0x6f, 0x73, 0x69, 0x74, 0x69, 0x6f, 0x6e, 0x73, 0x2f, 0x66, 0x6e, 0x6f, 0x5f,
	0x70, 0x6f, 0x73, 0x2e, 0x70, 0x72, 0x6f, 0x74, 0x6f, 0x12, 0x09, 0x70, 0x6f, 0x73, 0x69, 0x74,
	0x69, 0x6f, 0x6e, 0x73, 0x22, 0x41, 0x0a, 0x12, 0x46, 0x6e, 0x6f, 0x50, 0x6f, 0x73, 0x69, 0x74,
	0x69, 0x6f, 0x6e, 0x52, 0x65, 0x71, 0x75, 0x65, 0x73, 0x74, 0x12, 0x2b, 0x0a, 0x12, 0x46, 0x43,
	0x50, 0x5f, 0x43, 0x4c, 0x4d, 0x5f, 0x4d, 0x54, 0x43, 0x48, 0x5f, 0x41, 0x43, 0x43, 0x4e, 0x54,
	0x18, 0x01, 0x20, 0x01, 0x28, 0x09, 0x52, 0x0f, 0x46, 0x43, 0x50, 0x43, 0x4c, 0x4d, 0x4d, 0x54,
	0x43, 0x48, 0x41, 0x43, 0x43, 0x4e, 0x54, 0x22, 0xa5, 0x04, 0x0a, 0x09, 0x46, 0x63, 0x70, 0x44,
	0x65, 0x74, 0x61, 0x69, 0x6c, 0x12, 0x21, 0x0a, 0x0c, 0x46, 0x46, 0x4f, 0x5f, 0x43, 0x4f, 0x4e,
	0x54, 0x52, 0x41, 0x43, 0x54, 0x18, 0x01, 0x20, 0x01, 0x28, 0x09, 0x52, 0x0b, 0x46, 0x46, 0x4f,
	0x43, 0x4f, 0x4e, 0x54, 0x52, 0x41, 0x43, 0x54, 0x12, 0x19, 0x0a, 0x08, 0x46, 0x46, 0x4f, 0x5f,
	0x50, 0x53, 0x54, 0x4e, 0x18, 0x02, 0x20, 0x01, 0x28, 0x09, 0x52, 0x07, 0x46, 0x46, 0x4f, 0x50,
	0x53, 0x54, 0x4e, 0x12, 0x17, 0x0a, 0x07, 0x46, 0x46, 0x4f, 0x5f, 0x51, 0x54, 0x59, 0x18, 0x03,
	0x20, 0x01, 0x28, 0x05, 0x52, 0x06, 0x46, 0x46, 0x4f, 0x51, 0x54, 0x59, 0x12, 0x1e, 0x0a, 0x0b,
	0x46, 0x46, 0x4f, 0x5f, 0x41, 0x56, 0x47, 0x5f, 0x50, 0x52, 0x43, 0x18, 0x04, 0x20, 0x01, 0x28,
	0x02, 0x52, 0x09, 0x46, 0x46, 0x4f, 0x41, 0x56, 0x47, 0x50, 0x52, 0x43, 0x12, 0x20, 0x0a, 0x0c,
	0x46, 0x43, 0x50, 0x5f, 0x58, 0x43, 0x48, 0x4e, 0x47, 0x5f, 0x43, 0x44, 0x18, 0x05, 0x20, 0x01,
	0x28, 0x09, 0x52, 0x0a, 0x46, 0x43, 0x50, 0x58, 0x43, 0x48, 0x4e, 0x47, 0x43, 0x44, 0x12, 0x20,
	0x0a, 0x0c, 0x46, 0x43, 0x50, 0x5f, 0x49, 0x42, 0x55, 0x59, 0x5f, 0x51, 0x54, 0x59, 0x18, 0x06,
	0x20, 0x01, 0x28, 0x05, 0x52, 0x0a, 0x46, 0x43, 0x50, 0x49, 0x42, 0x55, 0x59, 0x51, 0x54, 0x59,
	0x12, 0x2b, 0x0a, 0x12, 0x46, 0x43, 0x50, 0x5f, 0x43, 0x4c, 0x4d, 0x5f, 0x4d, 0x54, 0x43, 0x48,
	0x5f, 0x41, 0x43, 0x43, 0x4e, 0x54, 0x18, 0x07, 0x20, 0x01, 0x28, 0x09, 0x52, 0x0f, 0x46, 0x43,
	0x50, 0x43, 0x4c, 0x4d, 0x4d, 0x54, 0x43, 0x48, 0x41, 0x43, 0x43, 0x4e, 0x54, 0x12, 0x22, 0x0a,
	0x0d, 0x46, 0x43, 0x50, 0x5f, 0x50, 0x52, 0x44, 0x43, 0x54, 0x5f, 0x54, 0x59, 0x50, 0x18, 0x08,
	0x20, 0x01, 0x28, 0x09, 0x52, 0x0b, 0x46, 0x43, 0x50, 0x50, 0x52, 0x44, 0x43, 0x54, 0x54, 0x59,
	0x50, 0x12, 0x1d, 0x0a, 0x0a, 0x46, 0x43, 0x50, 0x5f, 0x49, 0x4e, 0x44, 0x53, 0x54, 0x4b, 0x18,
	0x09, 0x20, 0x01, 0x28, 0x09, 0x52, 0x09, 0x46, 0x43, 0x50, 0x49, 0x4e, 0x44, 0x53, 0x54, 0x4b,
	0x12, 0x21, 0x0a, 0x0c, 0x46, 0x43, 0x50, 0x5f, 0x55, 0x4e, 0x44, 0x52, 0x4c, 0x59, 0x4e, 0x47,
	0x18, 0x0a, 0x20, 0x01, 0x28, 0x09, 0x52, 0x0b, 0x46, 0x43, 0x50, 0x55, 0x4e, 0x44, 0x52, 0x4c,
	0x59, 0x4e, 0x47, 0x12, 0x20, 0x0a, 0x0c, 0x46, 0x43, 0x50, 0x5f, 0x45, 0x58, 0x50, 0x52, 0x59,
	0x5f, 0x44, 0x54, 0x18, 0x0b, 0x20, 0x01, 0x28, 0x09, 0x52, 0x0a, 0x46, 0x43, 0x50, 0x45, 0x58,
	0x50, 0x52, 0x59, 0x44, 0x54, 0x12, 0x20, 0x0a, 0x0c, 0x46, 0x43, 0x50, 0x5f, 0x45, 0x58, 0x45,
	0x52, 0x5f, 0x54, 0x59, 0x50, 0x18, 0x0c, 0x20, 0x01, 0x28, 0x09, 0x52, 0x0a, 0x46, 0x43, 0x50,
	0x45, 0x58, 0x45, 0x52, 0x54, 0x59, 0x50, 0x12, 0x1e, 0x0a, 0x0b, 0x46, 0x43, 0x50, 0x5f, 0x4f,
	0x50, 0x54, 0x5f, 0x54, 0x59, 0x50, 0x18, 0x0d, 0x20, 0x01, 0x28, 0x09, 0x52, 0x09, 0x46, 0x43,
	0x50, 0x4f, 0x50, 0x54, 0x54, 0x59, 0x50, 0x12, 0x20, 0x0a, 0x0c, 0x46, 0x43, 0x50, 0x5f, 0x53,
	0x54, 0x52, 0x4b, 0x5f, 0x50, 0x52, 0x43, 0x18, 0x0e, 0x20, 0x01, 0x28, 0x02, 0x52, 0x0a, 0x46,
	0x43, 0x50, 0x53, 0x54, 0x52, 0x4b, 0x50, 0x52, 0x43, 0x12, 0x1c, 0x0a, 0x0a, 0x46, 0x43, 0x50,
	0x5f, 0x55, 0x43, 0x43, 0x5f, 0x43, 0x44, 0x18, 0x0f, 0x20, 0x01, 0x28, 0x09, 0x52, 0x08, 0x46,
	0x43, 0x50, 0x55, 0x43, 0x43, 0x43, 0x44, 0x12, 0x26, 0x0a, 0x0f, 0x46, 0x43, 0x50, 0x5f, 0x4f,
	0x50, 0x4e, 0x50, 0x53, 0x54, 0x4e, 0x5f, 0x46, 0x4c, 0x57, 0x18, 0x10, 0x20, 0x01, 0x28, 0x09,
	0x52, 0x0d, 0x46, 0x43, 0x50, 0x4f, 0x50, 0x4e, 0x50, 0x53, 0x54, 0x4e, 0x46, 0x4c, 0x57, 0x22,
	0x4d, 0x0a, 0x15, 0x46, 0x63, 0x70, 0x44, 0x65, 0x74, 0x61, 0x69, 0x6c, 0x4c, 0x69, 0x73, 0x74,
	0x52, 0x65, 0x73, 0x70, 0x6f, 0x6e, 0x73, 0x65, 0x12, 0x34, 0x0a, 0x0a, 0x46, 0x63, 0x70, 0x44,
	0x65, 0x74, 0x61, 0x69, 0x6c, 0x73, 0x18, 0x01, 0x20, 0x03, 0x28, 0x0b, 0x32, 0x14, 0x2e, 0x70,
	0x6f, 0x73, 0x69, 0x74, 0x69, 0x6f, 0x6e, 0x73, 0x2e, 0x46, 0x63, 0x70, 0x44, 0x65, 0x74, 0x61,
	0x69, 0x6c, 0x52, 0x0a, 0x46, 0x63, 0x70, 0x44, 0x65, 0x74, 0x61, 0x69, 0x6c, 0x73, 0x32, 0x67,
	0x0a, 0x12, 0x46, 0x6e, 0x6f, 0x50, 0x6f, 0x73, 0x69, 0x74, 0x69, 0x6f, 0x6e, 0x53, 0x65, 0x72,
	0x76, 0x69, 0x63, 0x65, 0x12, 0x51, 0x0a, 0x0e, 0x47, 0x65, 0x74, 0x46, 0x4e, 0x4f, 0x50, 0x6f,
	0x73, 0x69, 0x74, 0x69, 0x6f, 0x6e, 0x12, 0x1d, 0x2e, 0x70, 0x6f, 0x73, 0x69, 0x74, 0x69, 0x6f,
	0x6e, 0x73, 0x2e, 0x46, 0x6e, 0x6f, 0x50, 0x6f, 0x73, 0x69, 0x74, 0x69, 0x6f, 0x6e, 0x52, 0x65,
	0x71, 0x75, 0x65, 0x73, 0x74, 0x1a, 0x20, 0x2e, 0x70, 0x6f, 0x73, 0x69, 0x74, 0x69, 0x6f, 0x6e,
	0x73, 0x2e, 0x46, 0x63, 0x70, 0x44, 0x65, 0x74, 0x61, 0x69, 0x6c, 0x4c, 0x69, 0x73, 0x74, 0x52,
	0x65, 0x73, 0x70, 0x6f, 0x6e, 0x73, 0x65, 0x42, 0x03, 0x5a, 0x01, 0x2e, 0x62, 0x06, 0x70, 0x72,
	0x6f, 0x74, 0x6f, 0x33,
}

var (
	file_positions_fno_pos_proto_rawDescOnce sync.Once
	file_positions_fno_pos_proto_rawDescData = file_positions_fno_pos_proto_rawDesc
)

func file_positions_fno_pos_proto_rawDescGZIP() []byte {
	file_positions_fno_pos_proto_rawDescOnce.Do(func() {
		file_positions_fno_pos_proto_rawDescData = protoimpl.X.CompressGZIP(file_positions_fno_pos_proto_rawDescData)
	})
	return file_positions_fno_pos_proto_rawDescData
}

var file_positions_fno_pos_proto_msgTypes = make([]protoimpl.MessageInfo, 3)
var file_positions_fno_pos_proto_goTypes = []any{
	(*FnoPositionRequest)(nil),    // 0: positions.FnoPositionRequest
	(*FcpDetail)(nil),             // 1: positions.FcpDetail
	(*FcpDetailListResponse)(nil), // 2: positions.FcpDetailListResponse
}
var file_positions_fno_pos_proto_depIdxs = []int32{
	1, // 0: positions.FcpDetailListResponse.FcpDetails:type_name -> positions.FcpDetail
	0, // 1: positions.FnoPositionService.GetFNOPosition:input_type -> positions.FnoPositionRequest
	2, // 2: positions.FnoPositionService.GetFNOPosition:output_type -> positions.FcpDetailListResponse
	2, // [2:3] is the sub-list for method output_type
	1, // [1:2] is the sub-list for method input_type
	1, // [1:1] is the sub-list for extension type_name
	1, // [1:1] is the sub-list for extension extendee
	0, // [0:1] is the sub-list for field type_name
}

func init() { file_positions_fno_pos_proto_init() }
func file_positions_fno_pos_proto_init() {
	if File_positions_fno_pos_proto != nil {
		return
	}
	if !protoimpl.UnsafeEnabled {
		file_positions_fno_pos_proto_msgTypes[0].Exporter = func(v any, i int) any {
			switch v := v.(*FnoPositionRequest); i {
			case 0:
				return &v.state
			case 1:
				return &v.sizeCache
			case 2:
				return &v.unknownFields
			default:
				return nil
			}
		}
		file_positions_fno_pos_proto_msgTypes[1].Exporter = func(v any, i int) any {
			switch v := v.(*FcpDetail); i {
			case 0:
				return &v.state
			case 1:
				return &v.sizeCache
			case 2:
				return &v.unknownFields
			default:
				return nil
			}
		}
		file_positions_fno_pos_proto_msgTypes[2].Exporter = func(v any, i int) any {
			switch v := v.(*FcpDetailListResponse); i {
			case 0:
				return &v.state
			case 1:
				return &v.sizeCache
			case 2:
				return &v.unknownFields
			default:
				return nil
			}
		}
	}
	type x struct{}
	out := protoimpl.TypeBuilder{
		File: protoimpl.DescBuilder{
			GoPackagePath: reflect.TypeOf(x{}).PkgPath(),
			RawDescriptor: file_positions_fno_pos_proto_rawDesc,
			NumEnums:      0,
			NumMessages:   3,
			NumExtensions: 0,
			NumServices:   1,
		},
		GoTypes:           file_positions_fno_pos_proto_goTypes,
		DependencyIndexes: file_positions_fno_pos_proto_depIdxs,
		MessageInfos:      file_positions_fno_pos_proto_msgTypes,
	}.Build()
	File_positions_fno_pos_proto = out.File
	file_positions_fno_pos_proto_rawDesc = nil
	file_positions_fno_pos_proto_goTypes = nil
	file_positions_fno_pos_proto_depIdxs = nil
}
